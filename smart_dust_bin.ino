#include <Servo.h>

#include <Adafruit_LiquidCrystal.h>



//LiquidCrystal lcd = LiquidCrystal(10,9,8,7,6,5); // Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):

Servo servo;

Adafruit_LiquidCrystal lcd(0);

const int trigPin = 7;
const int echoPin = 11;
float time, distance;
void setup() 
{
    lcd.begin(16, 2); // Specify the LCD's number of columns and rows. Change to (20, 4) for a 20x4 LCD
    pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  
  Serial.begin(9600);
    servo.attach(9);
  
}

void loop() 
{
digitalWrite(trigPin, LOW);  
delayMicroseconds(2);  
digitalWrite(trigPin, HIGH);  
delayMicroseconds(10);  
digitalWrite(trigPin, LOW);  

time = pulseIn(echoPin, HIGH);

distance = (time*.0343)/2;  

// For Serial Monitor
  
Serial.print("Distance:CM "); 
  
Serial.println(distance); 
  
  
 // For LCD Display
lcd.setCursor(0,0);
  
lcd.print("Distance in CM");
  
lcd.setCursor(0,1);
  
lcd.print(distance);
  

if (distance < 30){
  
  servo.write(90);
  
  delay(2000);
  
  servo.write(0);
  
  delay(1000);
}
  
  else{
    
    servo.write(0);
    
    delay(1000);
  }
  

  
  

}
