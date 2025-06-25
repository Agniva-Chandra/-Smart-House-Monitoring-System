# 🌾 Smart Agriculture Monitoring System
A compact IoT-based solution to monitor essential environmental parameters like temperature, humidity, gas, soil moisture, and rain detection. Displays real-time data on an OLED and via Serial Monitor.

## 📝 Description
This project uses sensors like DHT22, MQ2, Rain, and Soil Moisture along with a 128x64 OLED display to monitor agricultural conditions. It helps in creating a smart, efficient, and sustainable farming environment.

## 🚀 Features
🌡️ Temperature & Humidity monitoring (DHT22)

🌧️ Rain detection (analog sensor)

💨 Gas level monitoring (MQ2 sensor)

🌱 Soil moisture status (Wet/Dry)

📺 Real-time OLED display output

🖥️ Serial Monitor support for debugging

🪶 Low power, field-deployable prototype

## 🔌 Circuit Diagram


![image](https://github.com/user-attachments/assets/e64bbbb1-22cf-479b-ae6b-6619faac6619)

## 🧾 Components List

| Component                    | Quantity     |
|-----------------------------|--------------|
| Arduino Uno / Nano          | 1            |
| DHT22 Temperature Sensor    | 1            |
| MQ2 Gas Sensor              | 1            |
| Analog Rain Sensor          | 1            |
| Soil Moisture Sensor        | 1            |
| OLED Display 128x64 I2C     | 1            |
| Breadboard + Jumper Wires   | As needed    |
| Power Source (USB or Battery) | 1          |

---

## 📊 Components Connection Chart

| Component       | VCC  | GND  | Signal Pin                |
|----------------|------|------|---------------------------|
| **DHT22**       | 5V   | GND  | D2                        |
| **MQ2 Sensor**  | 5V   | GND  | A1 (Analog Out)           |
| **Rain Sensor** | 5V   | GND  | A0 (Analog Out)           |
| **Soil Sensor** | 5V   | GND  | A2 (Analog Out)           |
| **OLED Display**| 5V   | GND  | SDA → A4, SCL → A5 (Uno)  |

> ⚠️ **Note:** On ESP32 or NodeMCU boards, I2C pins vary.  
> Example: `SDA = GPIO21`, `SCL = GPIO22` or `D2`, `D1`.  
> Adjust based on your board.

---

## 📦 Required Libraries

Install these libraries via the **Arduino Library Manager**:

- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
- [DHT sensor library](https://github.com/adafruit/DHT-sensor-library)
- [Adafruit Unified Sensor](https://github.com/adafruit/Adafruit_Sensor)


## 📈 Results

![image](https://github.com/user-attachments/assets/c321aadc-ac1a-4d4f-941d-71602b0fa4da)


![image](https://github.com/user-attachments/assets/b535f3c8-1c39-4bd8-a7a5-02c7a0ebde48)


Once the system is powered on:

- The OLED displays real-time data including:
  - 🌡️ **Temperature** (in °C)
  - 💧 **Humidity** (%)
  - 🌧️ **Rain Status** ("Rain" or "No Rain")
  - 💨 **Gas Level** (analog value)
  - 🌱 **Soil Status** ("Wet" or "Dry")
- All data also prints to the **Serial Monitor** for logging/debugging.
- Users can observe changes in soil moisture when watered,

## 🔧 Code Overview
Your main loop gathers data from all sensors and displays:

Temperature & Humidity (DHT22)

Rain status (Threshold < 400 = Rain)

Gas level (Raw analog value from MQ2)

Soil Moisture (Threshold < 500 = Wet)

OLED display for real-time viewing

## 🛠️ Future Development Ideas
🌐 Wi-Fi + Firebase integration (ESP32/ESP8266)

📱 Mobile/Web dashboard with charts

📦 SD card or cloud logging

🔔 SMS/Email alerts for dangerous gas levels or dry soil

💧 Auto irrigation control (relay + pump)

☀️ Solar powered design with battery monitoring
