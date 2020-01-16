#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h> 
#include <Wire.h>

#define BTN_NEXT 48
#define BTN_NEW 46

SoftwareSerial team1(2,3);
SoftwareSerial team2(4,5);
SoftwareSerial team3(6,7);
SoftwareSerial team4(8,9);
SoftwareSerial team5(10,11);
SoftwareSerial team6(54,55);
SoftwareSerial team7(56,57);
SoftwareSerial team8(58,59);
SoftwareSerial team9(60,61);

LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  Serial.begin(9600);
  team1.begin(9600);
  team2.begin(9600);
  team3.begin(9600);
  team4.begin(9600);
  team5.begin(9600);
  team6.begin(9600);
  team7.begin(9600);
  team8.begin(9600);
  team9.begin(9600);

  pinMode(BTN_NEXT,INPUT);
  pinMode(BTN_NEW,INPUT);
}

void loop() {
  
}
