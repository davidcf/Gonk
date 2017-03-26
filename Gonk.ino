#include "Arduino.h"
#include <Servo.h>
#include <Oscillator.h>
#include <US.h>
#include <Gonk.h>
Gonk Gonk;
//---------------------------------------------------------
//-- First step: Make sure the pins for servos are in the right position
/*
         ---------------
        |     O   O     |
        |---------------|
YR 3==> |               | <== YL 2
         ---------------
            ||     ||
RR 5==>   -----   ------  <== RL 4
         |-----   ------|
*/
  #define PIN_YL 2 //servo[2]
  #define PIN_YR 3 //servo[3]
  #define PIN_RL 4 //servo[4]
  #define PIN_RR 5 //servo[5]

//-- Movement parameters
int T=1000;              //Initial duration of movement
int moveId=0;            //Number of movement
int moveSize=15;         //Asociated with the height of some movementsgkk
//---------------------------------------------------------
bool obstacleDetected = false;

void setup(){
  //Set the servo pins
  Gonk.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR,true);
  Gonk.sing(S_connection); //Otto wake up!
  Gonk.home();
  delay(50);
  //Otto.sing(S_happy); // a happy Otto :)
}

void loop() {
  if(obstacleDetected){
               Gonk.sing(S_surprise);
               Gonk.playGesture(GonkFretful);
               Gonk.sing(S_fart3);
               Gonk.walk(2,1300,-1);
               Gonk.turn(2,1000,-1);
             delay(50);
             obstacleDetector();
             }
         else{
            Gonk.walk(1,1000,1);
            obstacleDetector();
        }
  }

void obstacleDetector(){
   int distance = Gonk.getDistance();
        if(distance<15){
          obstacleDetected = true;
        }else{
          obstacleDetected = false;
        }
}
