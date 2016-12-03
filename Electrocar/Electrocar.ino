//
//Electrocar
//Firmware for Arduino board on electric car. Communicates with controller via HC-05 BlueTooth Modules.
//By Zach Rash
//

#define BT_RX_PIN 10 //BlueTooth pins
#define BT_TX_PIN 7

#define ASpeed 3
#define BSpeed 11
#define ABrake 9
#define BBrake 8
#define ADir 12
#define BDir 13



#include <SoftwareSerial.h>
SoftwareSerial BTserial(BT_RX_PIN, BT_TX_PIN);

char message;

void setup() {
  Serial.begin(9600);
  BTserial.begin(38400);
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);

  digitalWrite(ABrake, LOW);  // No brakes
  digitalWrite(BBrake, LOW);
}
void loop() {
  
  // Check for BT signal.
  if (BTserial.available() > 0) {
    message = BTserial.read();
    Serial.println(message);
    
    // Polarities on motor B reversed -> BDir pin LOW = forward
    if (message == 'F') { 
      analogWrite(ASpeed, 255);
      analogWrite(BSpeed, 255);
      digitalWrite(ADir, HIGH);
      digitalWrite(BDir, LOW);
      }
   
    else if (message == 'B') {
      analogWrite(ASpeed, 255);
      analogWrite(BSpeed, 255);
      digitalWrite(ADir, LOW);
      digitalWrite(BDir, HIGH);
      }
  
    else if (message == 'L') {
      analogWrite(ASpeed, 255);
      analogWrite(BSpeed, 255);
      digitalWrite(ADir, HIGH);
      digitalWrite(BDir, HIGH);
      }
  
   else if (message == 'R') {
      analogWrite(ASpeed, 255);
      analogWrite(BSpeed, 255);
      digitalWrite(ADir, LOW);
      digitalWrite(BDir, LOW);
      }
  
    else {
      analogWrite(ASpeed, 0);
      analogWrite(BSpeed, 0);
      }
   
   }
  else {
    analogWrite(ASpeed, 0);
    analogWrite(BSpeed, 0);
  }
}
