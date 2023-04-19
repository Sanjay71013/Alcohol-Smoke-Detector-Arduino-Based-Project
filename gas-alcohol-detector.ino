#include <Servo.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int ledPin = 6;

int sensorPin = A1;

int gasSensor = A5;

int buzzerPin = 8;


Servo myservo;


int pos = 0;


int value;
int gasValue;


void setup()

{


Serial.begin(9600);

lcd.begin(16,2);


pinMode(ledPin,OUTPUT);
pinMode(buzzerPin, OUTPUT); 


 myservo.attach(10);

}

void rotateMotor(){
  for(int i = 0 ; i < 180 ; i++){
    myservo.write(i);
    delay(5);
  }
  for(int i = 180 ; i >= 0 ; i--){
    myservo.write(i);
    delay(5);
  }
}

void loop() 

{


int Value = analogRead(sensorPin);
int GasValue = analogRead(gasSensor);
// gasValue = map(gasValue, 0, 1023, 0, 255);
gasValue = analogRead(A5);
value = analogRead(A1);



lcd.print("Alcohollevel:");

lcd.println(value);

Serial.println(value);
Serial.println(gasValue);

if(GasValue>250){
  digitalWrite(buzzerPin, HIGH);
}
else{
  digitalWrite(buzzerPin, LOW);
}


if (Value > 475) 

{

    digitalWrite(ledPin,HIGH);

    

     lcd.setCursor(0, 2);

     lcd.print("Alert....!!!");

    Serial.print ("Alert");

    

      // myservo.write(100); 
      rotateMotor();

    

  } 

  else {

    digitalWrite(ledPin,LOW); 

    

      lcd.setCursor(0, 2);

      lcd.print("Normal... :)");

    Serial.print("Normal");

    

     myservo.write(0); 

  }


  



delay(1000);

lcd.clear();


}