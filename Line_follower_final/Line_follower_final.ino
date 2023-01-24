#include <AFMotor.h>
AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

//**********5 Channel IR Sensor Connection**********//
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4
#define near A5
//*************************************************//

void setup() {
  motor1.setSpeed(75);
  motor2.setSpeed(75);
}

void loop() {
  //Reading Sensor Values
  int s1 = analogRead(ir1);  //Lest most Sensor
  int s2 = analogRead(ir2);  //Left Sensor
  int s3 = analogRead(ir3);  //Middle Sensor
  int s4 = analogRead(ir4);  //Right Sensor
  int s5 = analogRead(ir5);  //Right Most Sensor
  int near = analogRead(near);


  //if only middle sensor detects black line
  if((s2 < 500) && (s3 < 500) && (s4 < 500))
  {
    //going forward with full speed 
     //set speed for motor 1 at 50%
    motor1.run(FORWARD);//send motor 1 to Foarward rotation
    //set speed for motor 1 at 50%
    motor2.run(FORWARD);//send motor 1 to Foarward rotation
  }

  else if((s2 > 500) && (s3 < 500) && (s4 > 500))
  {
    //going forward with full speed 
     //set speed for motor 1 at 50%
    motor1.run(FORWARD);//send motor 1 to Foarward rotation
    //set speed for motor 1 at 50%
    motor2.run(FORWARD);//send motor 1 to Foarward rotation
  }
  if((s2 < 500) && (s4 < 500))
  {
    //going forward with full speed 
     //set speed for motor 1 at 50%
    motor1.run(FORWARD);//send motor 1 to Foarward rotation
    //set speed for motor 1 at 50%
    motor2.run(FORWARD);//send motor 1 to Foarward rotation
  }
  
  //if only left sensor detects black line
  else if((s2 < 500) && (s3 < 500) && (s4 > 500))
  {
    //going forward with full speed 
     //set speed for motor 1 at 50%
    motor1.run(FORWARD);//send motor 1 to Foarward rotation
    //set speed for motor 1 at 50%
    motor2.run(RELEASE);//send motor 1 to Foarward rotation
  }

  //if only left sensor detects black line
  else if((s2 < 500) && (s3 > 500) && (s4 > 500))
  {
    //going forward with full speed 
     //set speed for motor 1 at 50%
    motor1.run(FORWARD);//send motor 1 to Foarward rotation
    //set speed for motor 1 at 50%
    motor2.run(RELEASE);//send motor 1 to Foarward rotation
  }

  //if only right sensor detects black line
  else if((s2 > 500) && (s3 < 500) && (s4 < 500))
  {
    //going forward with full speed 
     //set speed for motor 1 at 50%
    motor1.run(RELEASE);//send motor 1 to Foarward rotation
    //set speed for motor 1 at 50%
    motor2.run(FORWARD);//send motor 1 to Foarward rotation
  }

  //if only right sensor detects black line
  else if((s2 > 500) && (s3 > 500) && (s4 < 500))
  {
    //going forward with full speed 
     //set speed for motor 1 at 50%
    motor1.run(RELEASE);//send motor 1 to Foarward rotation
    //set speed for motor 1 at 50%
    motor2.run(FORWARD);//send motor 1 to Foarward rotation
  }
  else if ((s5 < 500))
  {
    motor1.run(FORWARD);//send motor 1 to Foarward rotation
    //set speed for motor 1 at 50%
    motor2.run(RELEASE);
   //send motor 1 to Foarward rotation
  }

  else if ((s1 < 500))
  {
    motor1.run(RELEASE);//send motor 1 to Foarward rotation
    //set speed for motor 1 at 50%
    motor2.run(FORWARD);
    //send motor 1 to Foarward rotation
  }
  //if all sensors are on a white line
  else if((s2 > 500) && (s3 > 500) && (s4 > 500))
  {
    motor1.run(RELEASE);//send motor 1 to STOP rotation
    motor2.run(RELEASE);//send motor 2 to STOP rotation
  }

  else if((near < 500))
  {
    motor1.run(RELEASE);//send motor 1 to STOP rotation
    motor2.run(RELEASE);//send motor 2 to STOP rotation
  }
}
