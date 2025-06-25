#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

// === Sensor Pin Definitions ===
#define DHTPIN 2
#define DHTTYPE DHT22
#define RAIN_SENSOR A0
#define MQ2_SENSOR A1
#define SOIL_SENSOR A2

// === OLED Setup ===
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  // No reset pin used with I2C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// === DHT Sensor ===
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  // === Initialize SSD1306 OLED ===
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C is I2C address
    Serial.println(F("❌ SSD1306 OLED not found!"));
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("🌾 Smart Agri System");
  display.display();
  delay(2000);
}

void loop() {
  // === Read Sensor Data ===
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int rain = analogRead(RAIN_SENSOR);
  int gas = analogRead(MQ2_SENSOR);
  int soil = analogRead(SOIL_SENSOR);

  // === Interpret Sensor Readings ===
  String rainStatus = (rain < 400) ? "Rain" : "No Rain";
  String soilStatus = (soil < 500) ? "Wet" : "Dry";

  // === Display on OLED ===
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(" Agri Monitor");
  display.print(" Temp: "); display.print(temp); display.println(" C");
  display.print(" Humid: "); display.print(hum); display.println(" %");
  display.print(" Rain: "); display.println(rainStatus);
  display.print(" Gas: "); display.println(gas);
  display.print(" Soil: "); display.println(soilStatus);
  display.display();

  delay(3000);
}
