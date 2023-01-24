#define BLYNK_TEMPLATE_ID "TMPLpN9Cr9fj"
#define BLYNK_DEVICE_NAME "Robot"
#define BLYNK_AUTH_TOKEN "IeEd4Wj2FYeVF4rUYZQVbPUu2nX5-ndK"

// Comment this out to disable prints and save space


#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "test";
char pass[] = "12345678";


Servo rh1;
Servo rh2;
Servo rh3;
Servo lh1;
Servo lh2;
Servo lh3;
Servo h;


static const int rh1Pin = 21;
static const int rh2Pin = 21;
static const int rh3Pin = 21;
static const int lh1Pin = 21;
static const int lh2Pin = 21;
static const int lh3Pin = 21;
static const int hPin = 21;


BLYNK_WRITE(V0)
{
  int s0 = param.asInt(); 
  rh1.write(s0);
  Serial.print("rh1 = ");
  Serial.println(s0);
}

BLYNK_WRITE(V1)
{
  int s0 = param.asInt(); 
  rh2.write(s0);
  Serial.print("rh2 = ");
  Serial.println(s0);
}

BLYNK_WRITE(V2)
{
  int s0 = param.asInt(); 
  rh3.write(s0);
  Serial.print("rh3 = ");
  Serial.println(s0);
}

BLYNK_WRITE(V3)
{
  int s0 = param.asInt(); 
  lh1.write(s0);
  Serial.print("lh1 = ");
  Serial.println(s0);
}

BLYNK_WRITE(V4)
{
  int s0 = param.asInt(); 
  lh2.write(s0);
  Serial.print("lh2 = ");
  Serial.println(s0);
}

BLYNK_WRITE(V5)
{
  int s0 = param.asInt(); 
  lh3.write(s0);
  Serial.print("lh3 = ");
  Serial.println(s0);
}

BLYNK_WRITE(V6)
{
  int s0 = param.asInt(); 
  h.write(s0);
  Serial.print("h = ");
  Serial.println(s0);
}








void setup()
{

  
  rh1.attach(rh1Pin);
  rh2.attach(rh2Pin);
  rh3.attach(rh3Pin);
  lh1.attach(lh1Pin);
  lh2.attach(lh2Pin);
  lh3.attach(lh3Pin);
  h.attach(hPin);
  
  
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");             
  }
  Serial.println("");
  Serial.println("WiFi connected. ");
  digitalWrite(2, HIGH);
  Blynk.begin(auth, ssid, pass);
  Serial.println("Start Project");
}

void loop() 
{
  Blynk.run();
}
