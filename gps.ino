#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// Pins for the NEO 7M GPS module
#define RX_PIN 16
#define TX_PIN 17

SoftwareSerial gpsSerial(RX_PIN, TX_PIN);
TinyGPSPlus gps;

void setup() {
  Serial.begin(115200);
  gpsSerial.begin(9600);
}

void loop() {
  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      if (gps.location.isValid()) {
        Serial.print("Latitude: ");
        Serial.println(gps.location.lat(), 6);
        Serial.print("Longitude: ");
        Serial.println(gps.location.lng(), 6);
        Serial.print("Altitude: ");
        Serial.println(gps.altitude.meters());
      } else {
        Serial.println("Waiting for GPS signal...");
      }
    }
  }
}
