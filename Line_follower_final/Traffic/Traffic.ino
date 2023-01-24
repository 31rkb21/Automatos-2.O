//150
//10
//50
//130
//35
//170
//10


#include<Servo.h>
const char r_b = 2;
const char y_b = 3;
const char g_b = 4;
const char n_b = 5;
int red = 6;
int yellow = 7;
int green = 8;

bool r_p = false;
bool y_p = false;
bool g_p = false;
bool n_p = false;

Servo r_u;
Servo r_d;
Servo l_h;

void setup(){
  Serial.begin(9600);
  pinMode(r_b, INPUT_PULLUP);
  pinMode(y_b, INPUT_PULLUP);
  pinMode(g_b, INPUT_PULLUP);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  
  r_u.attach(11);// right hand pin
  r_u.write(130);
  Serial.println("Right up servo ok");
  delay(500);
  r_d.attach(9);// right elbow pin
  r_d.write(170);
  Serial.println("Right down servo ok");
  delay(500);
  l_h.attach(10);//left hand pin
  l_h.write(150);
  Serial.println("Left servo ok");    
  delay(500);    
}

void loop(){
  bool r_bs = digitalRead(r_b);
  bool y_bs = digitalRead(y_b);
  bool g_bs = digitalRead(g_b);
  bool n_bs = digitalRead(n_b);
  if (r_bs == r_p)
  {
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    r_u.write(130);
    delay(100);
    r_d.write(170);
    delay(100);
    l_h.write(10);
    Serial.println("Hands up");
    delay(100);
    l_h.write(50);
    Serial.println("Hands Straight"); 
  }

  else if (y_bs == y_p)
  {
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);
    r_u.write(130);
    delay(100);
    r_d.write(170);
    delay(100);
    l_h.write(150);
    delay(100);
  }
  else if (g_bs == g_p)
  {
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
    l_h.write(150);
    delay(100); 
    r_u.write(35);
    delay(100);
    r_d.write(10);
    delay(100);
    r_d.write(170);
    delay(100);
    r_d.write(10);
    delay(100);
    r_d.write(170);
    delay(100);
    r_d.write(10);
    delay(100);
    r_d.write(170);
    delay(100);
    Serial.println("End.....");
  }  
}
