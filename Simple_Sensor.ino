#include "Adafruit_VL53L0X.h"
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT  32

int passiveBuzzer = 8;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,&Wire, -1);
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {

  pinMode(passiveBuzzer, OUTPUT);

  Serial.begin(115200);
  Serial.println(F("Testing"));

  Wire.begin();
  Wire.setClock(100000);

  // wait until serial port opens for native USB devices
  while (!Serial);

  Serial.println(F("Testing OLED and VL53L0X..."));

  // Initialize the OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (1);
  }
  Serial.println(F("OLED Initialized!"));

  // Sensor test
  Serial.println(F("Adafruit VL53L0X test"));
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  Serial.println(F("VL53L0X initialied!"));

    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
  
}


void loop() {

  VL53L0X_RangingMeasurementData_t measure;

  Serial.print(F("Reading a measurement... "));
  lox.rangingTest(&measure, false); // take measurement

  display.clearDisplay();

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    display.setCursor(0,0);
    float cm = measure.RangeMilliMeter/10;
    display.print(cm);
    display.print(F(" cm"));
    Serial.print(F("Distance (cm): ")); Serial.println(cm);
     // Check the range using if-else
  if (cm >= 0 && cm < 4) {
    tone(passiveBuzzer, 349.228); 
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("F")); // F
    display.setCursor(0, 16);
    display.print(cm);
  } else if (cm >= 4 && cm < 7) {
    tone(passiveBuzzer, 369.99);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("F#")); // F#
    display.setCursor(0, 16);
    display.print(cm);
  } else if (cm >= 7 && cm < 10) {
    tone(passiveBuzzer, 391.995); 
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("G")); // G
    display.setCursor(0, 16);
    display.print(cm);
  } else if (cm >= 10 && cm < 13) {
    tone(passiveBuzzer, 415.30); 
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("G#")); // G#
    display.setCursor(0, 16);
    display.print(cm);
  } else if (cm >= 13 && cm < 16) {
    tone(passiveBuzzer, 440); 
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("A")); // A
    display.setCursor(0, 16);
    display.print(cm);
  } else if (cm >= 16 && cm < 19) {
    tone(passiveBuzzer, 466.16); 
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("A#")); // A#
    display.setCursor(0, 16);
    display.print(cm);
  } else if (cm >= 19 && cm < 22) {
    tone(passiveBuzzer, 493.88); 
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("B")); // B
    display.setCursor(0, 16);
    display.print(cm);
  } else if (cm >= 22 && cm < 25) {
    tone(passiveBuzzer, 523.25); 
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("C")); // C
    display.setCursor(0, 16);
    display.print(cm);
  } else if (cm >= 25 && cm < 28) {
    tone(passiveBuzzer, 554.37); 
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("C#")); // C#
    display.setCursor(0, 16);
    display.print(cm);
  } else if (cm >= 28 && cm <= 31) {
    tone(passiveBuzzer, 587.33); 
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("D")); // D
    display.setCursor(0, 16);
    display.print(cm);
  } else if (cm >= 31 && cm < 34) {
    tone(passiveBuzzer, 622.25);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("D#")); // D#
    display.setCursor(0, 16);
    display.print(cm);
  } else if (cm >= 34 && cm < 37) {
    tone(passiveBuzzer, 659.25); 
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("E")); // E
    display.setCursor(0,16);
    display.print(cm);
  } else if (cm >= 37){
    display.clearDisplay();
    display.setCursor(0,0);
    Serial.println(F(" out of range "));
    display.print(F("N/A"));
    noTone(passiveBuzzer);
  }
  } else {
    display.setCursor(0,0);
    Serial.println(F(" out of range "));
    display.print(F("N/A"));
    noTone(passiveBuzzer);
  }
  
  display.display();
  delay(100);
}

