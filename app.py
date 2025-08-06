import streamlit as st
import requests

JAC_SERVER = "http://localhost:8000/walker/interpret_voice"
ESP32_IP = "http://172.31.118.97"  # Replace with your ESP32 IP
ESP32_ENDPOINT = f"{ESP32_IP}/led"

st.set_page_config(page_title="Command LED Controller", layout="centered")
st.title("🔊 Command-Controlled Dashboard")

prompt = st.text_input("💬 Enter command:", placeholder="e.g., turn off after 2 minutes")

if st.button("🚀 Send to LLM + ESP32"):
    if not prompt.strip():
        st.warning("Please enter a prompt.")
    else:
        with st.spinner("🧠 Contacting Jac LLM..."):
            try:
                res = requests.post(JAC_SERVER, json={"user_input": prompt})
                res.raise_for_status()
                data = res.json()
                reports = data.get("reports", [])
                if not reports:
                    st.error("❌ No response from LLM")
                else:
                    command_info = reports[0]
                    st.success(f"🎯 LLM Parsed: {command_info}")

                    with st.spinner("📡 Sending to ESP32..."):
                        r = requests.post(ESP32_ENDPOINT, json=command_info)
                        r.raise_for_status()
                        st.success("✅ Command sent to ESP32")

            except Exception as e:
                st.error(f"Error: {str(e)}")
