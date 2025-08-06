#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <WebServer.h>

const char* ssid = "TP-1124";
const char* password = "su11su11";

// LED pin definitions
#define YELLOW_LED_PIN    2
#define GREEN_LED_PIN  4
#define BLUE_LED_PIN   5

WebServer server(80);

// Pending action variables
bool hasPendingAction = false;
String pendingLed = "";
String pendingCommand = "";
unsigned long actionStartTime = 0;
unsigned long actionDelayMs = 0;

int getLedPin(const String& color) {
  if (color == "YELLOW") return YELLOW_LED_PIN;
  if (color == "GREEN") return GREEN_LED_PIN;
  if (color == "BLUE") return BLUE_LED_PIN;
  return -1;  // Invalid LED
}

void handleCommand() {
  if (!server.hasArg("plain")) {
    server.send(400, "text/plain", "Body missing");
    return;
  }

  String body = server.arg("plain");
  Serial.println("📥 Received JSON: " + body);

  DynamicJsonDocument doc(256);
  DeserializationError error = deserializeJson(doc, body);
  if (error) {
    server.send(400, "text/plain", "JSON parsing error");
    return;
  }

  String ledColor = doc["led"];
  String command = doc["command"];
  int delaySec = doc["delay"];
  int ledPin = getLedPin(ledColor);

  if (ledPin == -1) {
    server.send(400, "text/plain", "Invalid LED color");
    return;
  }

  unsigned long delayMs = delaySec * 1000;
  Serial.printf("🎯 LED: %s, Command: %s, Delay: %d sec\n", ledColor.c_str(), command.c_str(), delaySec);

  if (delayMs == 0) {
    if (command == "ON") {
      digitalWrite(ledPin, HIGH);
      Serial.printf("✅ %s LED turned ON immediately\n", ledColor.c_str());
    } else if (command == "OFF") {
      digitalWrite(ledPin, LOW);
      Serial.printf("✅ %s LED turned OFF immediately\n", ledColor.c_str());
    }
    hasPendingAction = false;
  } else {
    hasPendingAction = true;
    pendingLed = ledColor;
    pendingCommand = command;
    actionDelayMs = delayMs;
    actionStartTime = millis();
    Serial.printf("⏳ Scheduled %s %s after %d seconds...\n", ledColor.c_str(), command.c_str(), delaySec);
  }

  server.send(200, "text/plain", "OK");
}

void setup() {
  Serial.begin(115200);

  // Initialize LED pins
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  digitalWrite(YELLOW_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(BLUE_LED_PIN, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ WiFi connected");
  Serial.print("📡 IP Address: ");
  Serial.println(WiFi.localIP());

  // Start web server
  server.on("/led", HTTP_POST, handleCommand);
  server.begin();
  Serial.println("🌐 Web server started");
}

void loop() {
  server.handleClient();

  // Handle pending command after delay
  if (hasPendingAction && millis() - actionStartTime >= actionDelayMs) {
    int ledPin = getLedPin(pendingLed);
    if (ledPin != -1) {
      if (pendingCommand == "ON") {
        digitalWrite(ledPin, HIGH);
        Serial.printf("✅ %s LED turned ON after delay\n", pendingLed.c_str());
      } else if (pendingCommand == "OFF") {
        digitalWrite(ledPin, LOW);
        Serial.printf("✅ %s LED turned OFF after delay\n", pendingLed.c_str());
      }
    }
    hasPendingAction = false;
  }
}
