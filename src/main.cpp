#include <SoftwareSerial.h>
#include <DFR_Radar.h>
#include <Arduino.h>


// Connect Sensor TX to pin 2 (Arduino RX), Sensor RX to pin 3 (Arduino TX)
SoftwareSerial sensorSerial(2, 3);

void setup() {
  Serial.begin(57600);        // USB debugging
  sensorSerial.begin(57600);  // Sensor serial

  Serial.println("Initializing Radar...");
}

void loop() {
  // Check if sensor sent any data
  while (sensorSerial.available()) {
    byte incomingByte = sensorSerial.read();

    // Debug: print raw byte value
    Serial.print("Byte: ");
    Serial.println(incomingByte, HEX);

    // Example presence detection:
    // If byte equals 0x01 → presence detected
    // If byte equals 0x00 → no presence
    // These values depend on sensor's protocol
    if (incomingByte == 0x01) {
      Serial.println("Presence detected");
    } else if (incomingByte == 0x00) {
      Serial.println("No presence");
    }
  }

  delay(100); // Avoid flooding Serial Monitor
}
