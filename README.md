# 🎙️ Intelligent Command-Controlled LED System

An advanced IoT system that combines natural language processing, edge computing, and intelligent command interpretation to control LED lights through voice commands. Built with **Jac Language**, **Google Gemini AI**, **ESP32**, and **Streamlit**.

---

## 📋 Table of Contents

- [🎯 Overview](#-overview)
- [🏗️ High-Level Architecture](#️-high-level-architecture)
- [🔄 How It Works](#-how-it-works)
- [✨ Key Benefits](#-key-benefits)
- [⚡ Comparison with Traditional Voice Assistants](#-comparison-with-traditional-voice-assistants)
- [🧬 Why Jac Language?](#-why-jac-language)
- [🚀 Future Development Ideas](#-future-development-ideas)
- [🛠️ Technologies Used](#️-technologies-used)
- [⚙️ Setup & Installation](#️-setup--installation)
- [📱 Usage](#-usage)
- [🤝 Contributing](#-contributing)

---

## 🎯 Overview

This project demonstrates a sophisticated voice-controlled IoT system that interprets natural language commands in multiple languages (English, Sinhala, Singlish) and translates them into precise hardware actions. Unlike traditional voice assistants that rely on pre-programmed wake words and limited command sets, this system uses advanced AI to understand context, intent, and timing from conversational language.

### 🌟 Key Features

- **🌍 Multi-language Support**: Understands English, Sinhala, and Singlish commands
- **⏰ Time-based Control**: Schedule actions with natural language timing ("turn off after 2 minutes")
- **🎨 Multi-color LED Control**: Control RED, GREEN, and BLUE LEDs independently
- **🧠 Intelligent Parsing**: Uses Google Gemini AI for natural language understanding
- **📱 Web Interface**: User-friendly Streamlit dashboard
- **🔗 Real-time Communication**: Direct ESP32 integration for instant response
- **🔧 Modular Architecture**: Easily extensible for additional devices and commands

---

## 🏗️ High-Level Architecture

```
┌─────────────────┐    ┌──────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│   Streamlit     │    │   Jac Language   │    │  Google Gemini  │    │     ESP32       │
│   Frontend      │───▶│   Server         │───▶│      AI         │    │   Hardware      │
│   (client.py)   │    │   (new.jac)      │    │   (LLM API)     │    │ (streamlit.ino) │
└─────────────────┘    └──────────────────┘    └─────────────────┘    └─────────────────┘
         │                       │                       │                       │
         │                       │                       │                       │
    User Input              Command               Natural Language          LED Control
    "Turn red LED          Interpretation           Processing              (RED/GREEN/BLUE)
     on after 5 sec"       & Routing               & Validation             with Timing
```

### 🔧 Component Breakdown

1. **Frontend Layer (Streamlit)**
   - User interface for command input
   - Real-time feedback and status updates
   - Error handling and user guidance

2. **Intelligence Layer (Jac + Gemini AI)**
   - Natural language processing and understanding
   - Command parsing and validation
   - Multi-language support

3. **Hardware Layer (ESP32)**
   - Wi-Fi enabled microcontroller
   - LED control with timing mechanisms
   - HTTP server for command reception

4. **Communication Layer**
   - RESTful API communication
   - JSON data exchange
   - Real-time status reporting

---

## 🔄 How It Works

### 1. **Command Input**
User enters a natural language command like:
- "Turn on the green LED"
- "Switch off red light after 30 seconds"
- "ගහ කරණ LED එක 2 විනාඩියකට පස්සේ නිවන්න" (Sinhala)

### 2. **AI Processing**
The Jac server sends the command to Google Gemini AI which:
- Analyzes the natural language input
- Extracts key parameters: LED color, action (ON/OFF), delay time
- Returns structured JSON: `{led: "RED", command: "ON", delay: 30}`

### 3. **Hardware Execution**
ESP32 receives the structured command and:
- Validates the LED color and command
- Executes immediate actions or schedules delayed actions
- Provides feedback through serial monitoring

### 4. **User Feedback**
The system provides real-time updates:
- Command parsing results
- ESP32 communication status
- Action execution confirmation

---

## ✨ Key Benefits

### 🎯 **Flexibility & Customization**
- **No Wake Words**: No need for "Hey Google" or "Alexa" - direct command processing
- **Custom Commands**: Easily add new devices and command types
- **Language Agnostic**: Support for local languages and dialects

### 🔒 **Privacy & Security**
- **Local Processing**: Commands processed locally, not sent to cloud services continuously
- **No Always-Listening**: Commands are entered when needed, not always monitoring
- **Direct Control**: No dependency on external cloud services for basic operations

### ⚡ **Performance & Reliability**
- **Low Latency**: Direct ESP32 communication without cloud routing
- **Offline Capability**: Core functionality works without internet (except AI processing)
- **Real-time Response**: Immediate feedback and action execution

### 🛠️ **Developer-Friendly**
- **Open Source**: Full control over the system and customization
- **Modular Design**: Easy to extend and modify
- **Modern Tech Stack**: Built with cutting-edge tools and frameworks

---

## ⚡ Comparison with Traditional Voice Assistants

| Feature | This System | Google Assistant | Amazon Alexa | Apple Siri |
|---------|-------------|------------------|--------------|------------|
| **Wake Word Required** | ❌ No | ✅ "Hey Google" | ✅ "Alexa" | ✅ "Hey Siri" |
| **Multi-language Support** | ✅ English/Sinhala/Singlish | ✅ Limited | ✅ Limited | ✅ Limited |
| **Custom Commands** | ✅ Fully Customizable | ⚠️ Limited | ⚠️ Limited | ⚠️ Very Limited |
| **Privacy** | ✅ Local Processing | ❌ Cloud-based | ❌ Cloud-based | ❌ Cloud-based |
| **Hardware Integration** | ✅ Direct ESP32 Control | ⚠️ Via Cloud APIs | ⚠️ Via Skills | ⚠️ Via Shortcuts |
| **Offline Capability** | ✅ Core functions work | ❌ Internet Required | ❌ Internet Required | ❌ Internet Required |
| **Development Cost** | 💰 Low (Open Source) | 💰💰 API Costs | 💰💰 Development Time | 💰💰💰 Ecosystem Lock-in |
| **Response Time** | ⚡ ~1-2 seconds | ⚡ ~2-3 seconds | ⚡ ~2-4 seconds | ⚡ ~2-3 seconds |
| **Learning Curve** | 📚 Moderate | 📚 Easy | 📚 Easy | 📚 Easy |
| **Customization Level** | 🔧 Complete Control | 🔧 Limited | 🔧 Moderate | 🔧 Very Limited |

### 🎯 **Unique Advantages**

1. **No Vendor Lock-in**: Complete control over the system without dependency on Google, Amazon, or Apple ecosystems
2. **Local Language Support**: Can easily add support for any language or dialect
3. **Direct Hardware Control**: No need for cloud APIs or third-party integrations
4. **Educational Value**: Perfect for learning IoT, AI, and system integration
5. **Cost Effective**: No monthly subscriptions or API usage fees for basic operations

---

## 🧬 Why Jac Language?

Jac (Jaseci Actor-Oriented Programming) offers unique advantages for this IoT voice control system:

### 🎯 **AI-First Design**
- **Built-in LLM Integration**: Native support for AI/ML models with simple syntax
- **Intelligent Walkers**: Actor-based programming perfect for command processing workflows
- **Data-Driven**: Designed for modern AI applications from the ground up

### 🔧 **IoT-Optimized Features**
```jac
# Simple LLM integration - no complex API handling
def generate_command(user_input: str) -> dict byllm();

# Built-in REST API generation
obj __specs__ {
    static has methods: list = ["post"];
    static has auth: bool = False;
}
```

### 🚀 **Development Benefits**

1. **Rapid Prototyping**: Less boilerplate code compared to Python/Node.js
2. **Type Safety**: Built-in type system prevents common errors
3. **Scalability**: Actor model makes it easy to handle multiple concurrent requests
4. **Maintainability**: Clean, readable syntax reduces technical debt

### 🔄 **Comparison with Traditional Approaches**

| Aspect | Jac | Python Flask/FastAPI | Node.js Express | Java Spring |
|--------|-----|---------------------|-----------------|-------------|
| **LLM Integration** | ✅ Native | ⚠️ Manual Setup | ⚠️ Manual Setup | ⚠️ Complex Setup |
| **Boilerplate Code** | ✅ Minimal | ⚠️ Moderate | ⚠️ Moderate | ❌ Heavy |
| **Learning Curve** | 📚 Easy | 📚 Moderate | 📚 Moderate | 📚 Steep |
| **AI/ML Support** | ✅ Built-in | ⚠️ Libraries | ⚠️ Libraries | ⚠️ Complex |
| **REST API Creation** | ✅ Automatic | ⚠️ Manual | ⚠️ Manual | ⚠️ Manual |
| **Type Safety** | ✅ Strong | ⚠️ Optional | ❌ Weak | ✅ Strong |

---

## 🚀 Future Development Ideas

### 🎯 **Immediate Enhancements (1-2 months)**
- **Voice Input Integration**: Add speech-to-text for true voice control
- **Mobile App**: Native iOS/Android app with voice recording
- **Command History**: Store and replay previous commands
- **Device Status Monitoring**: Real-time LED status dashboard

### 🔧 **Advanced Features (3-6 months)**
- **Multi-Device Support**: Control multiple ESP32 devices simultaneously
- **Scene Management**: Create and save lighting scenes ("Movie mode", "Party lights")
- **Scheduling System**: Cron-like scheduling for automated actions
- **User Profiles**: Different users with personalized preferences

### 🌟 **Innovative Extensions (6-12 months)**
- **Smart Home Integration**: Connect with other IoT devices (sensors, cameras, appliances)
- **Machine Learning**: Learn user patterns and suggest optimizations
- **Gesture Control**: Add computer vision for gesture-based commands
- **Natural Conversations**: Multi-turn dialogue for complex command sequences

### 🔮 **Advanced AI Features**
- **Context Awareness**: Remember previous commands and current device states
- **Predictive Actions**: Suggest actions based on time, weather, or user behavior
- **Emotion Recognition**: Adjust lighting based on voice tone or facial expressions
- **Natural Language Generation**: System can explain its actions and suggest alternatives

### 🏢 **Enterprise Applications**
- **Office Automation**: Meeting room lighting and equipment control
- **Smart Buildings**: Integration with HVAC, security, and building management systems
- **Industrial IoT**: Factory floor equipment control with safety protocols
- **Healthcare**: Patient room environment control in hospitals

### 🌐 **Platform Extensions**
- **Cloud Deployment**: Scalable cloud version for multiple users
- **API Marketplace**: Allow third-party integrations and extensions
- **Plugin System**: Modular architecture for community contributions
- **Cross-Platform**: Support for Raspberry Pi, Arduino, and other microcontrollers

---

## 🛠️ Technologies Used

### **Core Framework**
- **🧬 Jac Language** - AI-first programming language for intelligent applications
- **🤖 Google Gemini 2.5 Flash** - Advanced natural language processing and understanding
- **🐍 Python 3.10+** - Backend runtime and Streamlit frontend
- **📱 Streamlit** - Rapid web application development framework

### **Hardware & IoT**
- **📡 ESP32** - Wi-Fi enabled microcontroller for hardware control
- **🔌 Arduino IDE** - Development environment for ESP32 programming
- **💡 RGB LEDs** - Hardware output devices for visual feedback

### **Communication & APIs**
- **🌐 HTTP/REST** - Communication protocol between components
- **📄 JSON** - Data exchange format for command structure
- **📊 ArduinoJson** - JSON parsing library for ESP32

### **Development Tools**
- **🔧 VS Code** - Recommended IDE with excellent Jac support
- **📦 Jaseci Runtime** - Required runtime for executing Jac programs
- **🐙 Git** - Version control and collaboration

---

## ⚙️ Setup & Installation

### 📋 **Prerequisites**
- Python 3.10 or higher
- Node.js (for npm packages if needed)
- Arduino IDE or PlatformIO
- ESP32 development board
- RGB LEDs and appropriate resistors

### 🔐 **Environment Setup**

1. **Install Jac Language**:
```powershell
pip install jaclang
jac --version
```

2. **Install Required Python Packages**:
```powershell
pip install streamlit requests jaclang
```

3. **Set up Gemini API Key**:
```powershell
$env:GEMINI_API_KEY="your_gemini_api_key_here"
```

4. **Install Jac LLM Plugin**:
```powershell
jac plugin install mtllm
```

### 🔧 **Hardware Setup**

1. **ESP32 Wiring**:
   - Red LED → GPIO 2 (with 220Ω resistor)
   - Green LED → GPIO 4 (with 220Ω resistor)
   - Blue LED → GPIO 5 (with 220Ω resistor)
   - Common ground connection

2. **Upload ESP32 Code**:
   - Open `streamlit.ino` in Arduino IDE
   - Update Wi-Fi credentials (`ssid` and `password`)
   - Select correct ESP32 board and port
   - Upload the code

### 🚀 **Running the System**

1. **Start Jac Server**:
```powershell
cd c:\Users\user\Desktop\streamlit
jac serve new.jac
```

2. **Launch Streamlit Frontend**:
```powershell
streamlit run client.py
```

3. **Access the Application**:
   - Open browser to `http://localhost:8501`
   - Ensure ESP32 is connected to Wi-Fi
   - Update ESP32 IP address in `client.py` if needed

---

## 📱 Usage

### 🎯 **Basic Commands**
- `"Turn on red LED"` - Immediately turn on red LED
- `"Switch off green light"` - Turn off green LED
- `"Turn blue LED on after 30 seconds"` - Delayed action
- `"நீல LED ஐ 2 நிमிடம் கழித்து அணைக்கவும்"` - Tamil command example

### ⏰ **Time-based Commands**
- `"Turn off all lights after 5 minutes"`
- `"Switch on green LED in 10 seconds"`
- `"Turn red light off after half a minute"`

### 🌍 **Multi-language Examples**
- English: `"Turn on the blue LED after 1 minute"`
- Sinhala: `"නිල් LED එක විනාඩි 2කට පස්සේ ඔන් කරන්න"`
- Singlish: `"Red light eka 30 second walata passe off karanna"`

### 🔍 **System Responses**
- ✅ **Success**: Command parsed and executed successfully
- ⚠️ **Warning**: Invalid input or missing parameters
- ❌ **Error**: Communication failure or hardware issues

---

## 🤝 Contributing

We welcome contributions to improve this voice-controlled LED system! Here are ways you can help:

### 🎯 **Areas for Contribution**
- **🌍 Language Support**: Add more languages and dialects
- **🔧 Hardware Integration**: Support for additional microcontrollers and devices
- **🎨 UI/UX Improvements**: Enhance the Streamlit interface
- **📚 Documentation**: Improve setup guides and API documentation
- **🧪 Testing**: Add unit tests and integration tests
- **🔒 Security**: Implement authentication and authorization features

### 📝 **Contributing Guidelines**
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Make your changes with clear commit messages
4. Add tests for new functionality
5. Update documentation as needed
6. Submit a pull request with detailed description

### 🐛 **Bug Reports**
Please include:
- Detailed description of the issue
- Steps to reproduce
- Expected vs actual behavior
- System information (OS, Python version, etc.)
- ESP32 serial output (if applicable)

### 💡 **Feature Requests**
- Describe the feature and its benefits
- Provide use cases and examples
- Consider implementation complexity
- Check existing issues to avoid duplicates

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🙏 Acknowledgments

- **Jaseci Team** for the innovative Jac programming language
- **Google** for providing the powerful Gemini AI model
- **Espressif** for the versatile ESP32 platform
- **Streamlit** for the excellent web framework
- **Open Source Community** for continuous inspiration and support

---

## 📞 Contact & Support

- **Project Repository**: [GitHub Link]
- **Documentation**: [Wiki/Docs Link]
- **Issues & Bug Reports**: [GitHub Issues]
- **Discussions**: [GitHub Discussions]

---

*Built with ❤️ by the IoT & AI Community*
