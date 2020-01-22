#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h> 
#include <Wire.h>
#include <math.h>

#define BTN_NEXT 48
#define BTN_NEW 46
#define SLEEP_TIME 3000
#define MAX 9
#define NEW 1
#define NEXT 2

#define A 21
#define B 22
#define C 23
#define D 24
#define E 25
#define F 26
#define G 27

typedef struct Data{
    short Team;
    short Time;
  }data;
  
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

data arr[9];
short segPin[]={A,B,C,D,E,F,G},index=0;
String tab[]={ "1001111", "0010010","0000110",
"1001100","0100100",
"0100000","0001111",
"0000000","0000100"};

void displaySeg(short num){
  for(int i=0;i!=7;i++){
    if(tab[num-1][i]=="1")
      digitalWrite(segPin[i], HIGH);
    else
      digitalWrite(segPin[i], LOW);
  }
}

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

data readBT(SoftwareSerial bt,int team){
  data d;
  bt.write("R");
  delay(100);
  if(bt.available()){
    d.Team=team;
    d.Time=strToInt(bt.readString());
  }else{
    d.Team=team;
    d.Time=9999;
  }
  return d;
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

  for(short i=0;i!=7;i++)
    pinMode(segPin[i],OUTPUT);
}

void loop() {
  short act=0;
  while(act==0){
    delay(50);
    if(digitalRead(BTN_NEXT))
      act=NEXT;
    if(digitalRead(BTN_NEW))
      act=NEW;
  }
  delay(100);
  if(act=NEXT){
    index++;
    displaySeg(arr[index].Team);
  }
  else if(act=NEW){
    index=0;
    team1.write("S");
    team2.write("S");
    team3.write("S");
    team4.write("S");
    team5.write("S");
    team6.write("S");
    team7.write("S");
    team8.write("S");
    team9.write("S");

    delay(SLEEP_TIME);

    arr[0]=readBT(team1,1);
    arr[1]=readBT(team2,2);
    arr[2]=readBT(team3,3);
    arr[3]=readBT(team4,4);
    arr[4]=readBT(team5,5);
    arr[5]=readBT(team6,6);
    arr[6]=readBT(team7,7);
    arr[7]=readBT(team8,8);
    arr[8]=readBT(team9,9);

    sort();

    displaySeg(arr[index].Team);
  }
}
