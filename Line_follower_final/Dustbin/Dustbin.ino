#include <Servo.h>   //servo library
Servo servo;   
int servoPin = 11;
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;


void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo.write(0);         //close cap on power on 
} 

void loop() {  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;
  Serial.print("Distance: "); // Prints string "Distance" on the LCD
  Serial.print(distanceCm); // Prints the distance value from the sensor
  Serial.println(" cm");
  delay(10);
  Serial.print("Distance: ");
  Serial.print(distanceInch);
  Serial.println(" inch");
  delay(10);
  
  if ( distanceInch < 10 ) {
    servo.write(0);  
    delay(3000);       
    servo.write(150);    
    delay(1000);      
  }
}
