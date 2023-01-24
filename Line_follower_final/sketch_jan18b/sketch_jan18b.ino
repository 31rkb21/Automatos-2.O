#include <SoftwareSerial.h>
#include "BluetoothSerial.h"
#define MAKEWORD(v1,v2)   ((((UINT16)(v1))<<8)+(UINT16)(v2))
#define LED 2
#define rly1 23  //D23  Relay 1 
#define rly2 22  //D22 Relay 2
#define rly3 21  //D21 Relay 3
#define rly4 19  //D19 Relay 4

#define sws1 13  //D13  Switch1
#define sws2 12  //D12 Switch2
#define sws3 14  //D14 Switch3
#define sws4 27  //D27 Switch4

bool flg ;
char btx[32];
char str[32];
char str2[8];
char str12[32];
unsigned char cnt, cnt2, cnt3 ;
int ir_pinstate ;

unsigned char aa, bb, cc;
BluetoothSerial SerialBT;



void setup() {  
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  pinMode(rly1, OUTPUT);
  pinMode(rly2, OUTPUT);
  pinMode(rly3, OUTPUT);
  pinMode(rly4, OUTPUT);

  pinMode(sws1, INPUT_PULLUP);
  pinMode(sws2, INPUT_PULLUP);
  pinMode(sws3, INPUT_PULLUP);
  pinMode(sws4, INPUT_PULLUP);
  
  SerialBT.begin("LT_32"); //Bluetooth device name
  Serial.println("\nThe device started, now you can pair it with bluetooth!");
  //Serial.println("start timer");   
  str12[0]=0;
}

void loop()
{
      if(digitalRead(sws1)==0){
      if(digitalRead(rly1)==0){digitalWrite(rly1, HIGH);} 
      else {digitalWrite(rly1,LOW);}}

      if(digitalRead(sws2)==0){
      if(digitalRead(rly2)==0){digitalWrite(rly2, HIGH);} 
      else {digitalWrite(rly2,LOW);}}

      if(digitalRead(sws3)==0){
      if(digitalRead(rly3)==0){digitalWrite(rly3, HIGH);} 
      else {digitalWrite(rly3,LOW);}}    

      if(digitalRead(sws4)==0){
      if(digitalRead(rly4)==0){digitalWrite(rly4, HIGH);} 
      else {digitalWrite(rly4,LOW);}}        

while(Serial.available()){
  //HC12.print(Serial.readString());
  char add1 = Serial.read();
  if( add1 != '\n'){
        str[cnt++] = add1;
  }
  else 
  {
    str[cnt]= '\0';
    cnt=0;
    //HC12.print("Server :");
    SerialBT.println(str);
    //if(strstr(str,"HC12")!=NULL)
    //{HC12.println("ITS From HC12");}// str[0]='\0';}
  }    
  }
  

  if(SerialBT.available()) {  
    char bt = SerialBT.read();
    if(bt !='\n'){
      btx[cnt3++]= bt;
    }
    else
    {
      btx[cnt3]='\0'; cnt3=0;
      SerialBT.println(btx);
      Serial.println(btx);

      if(strstr(btx,"LED")!=NULL){ btx[0]='\0';
      if(digitalRead(LED)==0){digitalWrite(LED, HIGH);} 
      else {digitalWrite(LED,LOW);}
      }
      
      if(btx=="LD1"){
      if(digitalRead(rly1)==0){digitalWrite(rly1, HIGH);} 
      else {digitalWrite(rly1,LOW);}
      }

      if(btx=="LD2"){
      if(digitalRead(rly2)==0){digitalWrite(rly2, HIGH);} 
      else {digitalWrite(rly2,LOW);}
      }
      
      if(btx=="LD3"){
      if(digitalRead(rly3)==0){digitalWrite(rly3, HIGH);} 
      else {digitalWrite(rly3,LOW);}
      }
      
      if(btx=="LD4"){
      if(digitalRead(rly4)==0){digitalWrite(rly4, HIGH);} 
      else {digitalWrite(rly4,LOW);}}      
        }
       }
     }
//===============================================
