#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h> 
#include <Wire.h>
#include <math.h>

#define BTN_NEXT 48
#define BTN_NEW 46
#define MAX 9

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

typedef struct Data{
    short Tema;
    short Time;
  }data;

data arr[9];

short strToInt(String inPut){
  short sec=0;
  for(short i=0;i!=4;i++)
    sec+=(inPut[i]-'0')*pow(10,4-i);
  
  return sec;
}

void sort(){
  for(short i=0;i!=MAX-1;i++)
    for(short j=i+1;j!=MAX;j++)
      if(arr[i].Time>arr[j].Time){
        data d=arr[i];
        arr[i]=arr[j];
        arr[j]=d;
      }
}


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
