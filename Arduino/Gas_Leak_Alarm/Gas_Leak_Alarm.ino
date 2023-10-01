/*

        Suppose All door and windows are off and that time the gas cylinder is leaking. Write a program 
        based on gas detection determination on time and at least one door or window near the Cylinder 
        open at that time and give an alarm.

*/
#include <Servo.h>
Servo myServo; // create servo object to control a servo
#define sensorPin A0
#define sensorLPG 300
void setup() {
  // put your setup code here, to run once:
  myServo.attach(9); 
  pinMode(A0,INPUT); //Not required Generally
  pinMode(buzzer,OUPUT);//Attaching the Servo Motor in Digital pin 9
}

void loop() {
  // put your main code here, to run repeatedly:
  if( analogRead(sensorPin) > sensorLPG){
      Serial.println("Concentration High %d", analogRead(sensorPin));
      myServo.write(90); //Changing the Servo Position
      delay(15); // Giving time to work mechanically
      for(int i=0; i< 10; i++) // Makes 10 Alarm sound
      {
          tone(buzzer,1000); //Sends 1Khz sound signal
          delay(1000);
          noTone(buzzer);
          delay(1000);
      }
  }
}
