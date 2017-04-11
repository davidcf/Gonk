#include "Arduino.h"
#include <Servo.h>
#include <Oscillator.h>
#include <US.h>
#include <Gonk.h>
Gonk Gonk;

  #define PIN_YL 2 //servo[2]
  #define PIN_YR 3 //servo[3]
  #define PIN_RL 4 //servo[4]
  #define PIN_RR 5 //servo[5]

//-- Movement parameters
int T=1000;              //Initial duration of movement
int moveId=0;            //Number of movement
int moveSize=15;         //Asociated with the height of some movementsgkk
//---------------------------------------------------------


void setup(){

  Gonk.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR,true);
  Gonk.home();
  delay(50);

}

void loop() {

  Gonk.walk(1,1000,1);

  }


