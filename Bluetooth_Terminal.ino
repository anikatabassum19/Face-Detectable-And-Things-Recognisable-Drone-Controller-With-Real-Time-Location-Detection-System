#include <SoftwareSerial.h>

SoftwareSerial gpsSerial(10, 11); // RX, TX for GPS module
SoftwareSerial bluetoothSerial(8, 9); // RX, TX for Bluetooth module

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  bluetoothSerial.begin(9600);
}

void loop() {
  if (gpsSerial.available()) {
    char c = gpsSerial.read();
    Serial.print(c); // Print GPS data to the Serial Monitor

    // Send GPS data to phone through Bluetooth
    bluetoothSerial.print(c);

    // You can add additional logic to determine the end of a GPS sentence (e.g., '$GPGGA')
    // and send a newline character to separate sentences for better readability on the phone.
    if (c == '\n') {
      bluetoothSerial.println();
    }
  }

  if (bluetoothSerial.available()) {
    char c = bluetoothSerial.read();
    // You can add additional logic to process incoming data from the phone if needed.
  }
}
