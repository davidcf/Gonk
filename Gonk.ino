#include "Arduino.h"
#include <Servo.h>
#include <Oscillator.h>
#include <US.h>
#include <Gonk.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


//Declaracion de Variables
const int LOGLEVEL = 1; // 1 activa trazas de log en serial, 0 Desactiva trazas

Gonk Gonk;

#define PIN_YL 2 //servo[2]
#define PIN_YR 3 //servo[3]
#define PIN_RL 4 //servo[4]
#define PIN_RR 5 //servo[5]

//-- Movement parameters
int T=1000;              //Initial duration of movement
int moveId=0;            //Number of movement
int moveSize=15;         //Asociated with the height of some movementsgkk

void setup(){

//Inicializamos
  Serial.begin(9600);
  Gonk.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR,true);
  //PONER SONIDO DE INICIALIZACION
  Gonk.home();
  delay(50);

}

void loop() {

//Gonk.walk(1,1000,1);
//Gonk.sing(S_sleeping);


//Serial.println(GetTemp(),1);
//delay(500);

  }

//#### FUNCIONES

void WriteLOG(String text)      // Escritura de log 1 activado 0 desactivado
{
	if ( LOGLEVEL == 1 ){
		Serial.println(text);
	}
}
double GetTemp(void)            // Medicion Temperatura interna
{
  unsigned int wADC;
  double t;

  ADMUX = (_BV(REFS1) | _BV(REFS0) | _BV(MUX3));
  ADCSRA |= _BV(ADEN);
  delay(20);
  ADCSRA |= _BV(ADSC);
  while (bit_is_set(ADCSRA,ADSC));
  wADC = ADCW;

  // Esto es la función a calibrar.
  t = (wADC - 324.31 ) / 1.22;
  return (t);
}
