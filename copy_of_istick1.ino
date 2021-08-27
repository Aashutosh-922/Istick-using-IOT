#include <LiquidCrystal.h>

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int trig1=8;
const int trig2=12;
const int trig3=13;
const int echo1=9;
const int echo2=11;
const int echo3=10;
const int buzzleftright = A4;


float duration1, distance1;
float duration2, distance2;
float duration3, distance3;

void setup() {
   pinMode(trig1, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(trig3, OUTPUT);
  
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(echo3, INPUT);
  
  pinMode(buzzleftright, OUTPUT);
  
  Serial.begin(9600);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  left();
  right();
  center();
  
  
}

void left(){
  
  delay(500);
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  
  duration1 = pulseIn(echo1, HIGH);
  distance1 = (duration1*.0343)/2;
  lcd.setCursor(0,0);
  lcd.noDisplay();
  
  if (distance1<70){
    tone(buzzleftright, 200);
    delay(100);
    noTone(buzzleftright);
  lcd.display();
    //delay(1000);
  lcd.print("Be careful ");
  lcd.setCursor(0,1);
  lcd.print(distance1);
  lcd.setCursor(6,1);
  lcd.print("cm in LEFT");
 
  //Serial.print("DistanceLeft: ");
  //Serial.println(distance1);
    
  }
  }


void center(){
  
  delay(500);
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  
  duration2 = pulseIn(echo2, HIGH);
  distance2 = (duration2*.0343)/2;
  lcd.setCursor(0,0);
  lcd.noDisplay();
  
  if (distance2<70){
   tone(buzzleftright, 250);
    delay(500);
   noTone(buzzleftright);
    
  lcd.display();
    //delay(1000);
  lcd.print("Be careful ");
  lcd.setCursor(0,1);
  lcd.print(distance2);
  lcd.setCursor(5,1);
  lcd.print("cm in FRONT");
 
  //Serial.print("DistanceLeft: ");
  //Serial.println(distance2;
  }
  
  
}

void right(){
  
  delay(500);
  digitalWrite(trig3, LOW);
  delayMicroseconds(2);
  digitalWrite(trig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3, LOW);
 
  duration3 = pulseIn(echo3, HIGH);
  distance3 = (duration3*.0343)/2;
  lcd.setCursor(0,0);
  lcd.noDisplay();
  
  if (distance3<70){
    tone(buzzleftright, 200);
    delay(150);
    noTone(buzzleftright);
    delay(90);
    tone(buzzleftright, 200);
    delay(150);
    noTone(buzzleftright);
  lcd.display();
    //delay(1000);
  lcd.print("Be careful ");
  lcd.setCursor(0,1);
  lcd.print(distance3);
  lcd.setCursor(5,1);
  lcd.print("cm in RIGHT");
 
  //Serial.print("DistanceLeft: ");
  //Serial.println(distance3);
  }

}