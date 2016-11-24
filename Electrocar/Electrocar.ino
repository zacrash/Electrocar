//Electrocar
//By Zach Rash

#define BT_RX_PIN 0 //BLE pins
#define BT_TX_PIN 1
#define LF_PIN 9  //Left motor forward pin
#define LB_PIN 6  //Left motor backward pin
#define RF_PIN 5  //Right motor forward pin
#define RB_PIN 3  //Right motor backward pin

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(BT_RX_PIN, BT_TX_PIN);

class Robot
{
  public:

  void run()
  {
    if (BT_RX_PIN == FORWARD) {
      LF_PIN = RF_Pin = HIGH;
    }
    if (BT_RX_PIN == LEFT) {
      LB_PIN = RF_PIN = HIGH;
    }
    if (BT_RX_PIN == RIGHT) {
      LF_PIN = RB_PIN = HIGH;
    }
    if (BT_RX_PIN == BACKWARD) {
      RB_PIN = LB_PIN = HIGH;
    }
    else
      LF_PIN = RF_PIN = LB_PIN = RB_PIN = LOW;
  }
};

Robot electrocar;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  electrocar.run();
}
