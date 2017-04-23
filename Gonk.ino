#include "Arduino.h"
#include <Servo.h>
#include <Oscillator.h>
#include <US.h>
#include <Gonk.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <PS2X_lib.h>

PS2X ps2x;

int error = 0;
byte vibrate = 0;

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

//Declaracion de Variables
const int LOGLEVEL = 1; // 1 activa trazas de log en serial, 0 Desactiva trazas

Gonk Gonk;
//Servos
#define PIN_YL 2
#define PIN_YR 3
#define PIN_RL 4
#define PIN_RR 5

//Pantalla
#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup(){

//Inicializamos pantalla
  Serial.begin(9600);
  //display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  //WriteLCD("Hace mucho tiempo en una galaxia muy muy  lejana...");

//Inicializamos joystick
  error = ps2x.config_gamepad(8,10,A0,9,true,true); //(clock, command, attention, data)
  if(error == 0)
	  {
		    Serial.println("Controlador encontrado y configurado");
		  }
	 else
		  {
		    Serial.println("Error, mando no encontrado");
	  }



//Inicializamos Gonk
  Gonk.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR,true);
  //PONER SONIDO DE INICIALIZACION
  Gonk.home();
  delay(50);


}

void loop() {
	 // Serial.println(error);
  //Gonk.walk(1,1400,1);
//Gonk.sing(S_sleeping);


//Serial.println(GetTemp(),1);
//delay(500);
GamePad();
//GameJoystick();

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
void WriteLCD(String Text)      // Escritura de una linea en LCD
{
	  display.clearDisplay();

	  display.setTextSize(0);
	  display.setTextColor(WHITE);
	  display.setCursor(0,0);
	  display.println(Text);
	  //display.println("Hace mucho tiempo en ");
	  //display.setCursor(0,8);
	  //display.println("una galaxia muy muy ");
	  //display.setCursor(0,16);
	  //display.println("lejana...");
	  display.display();
	  delay(200);
	  display.clearDisplay();
}
void GamePad()                  // Controles del mando
{

	  ps2x.read_gamepad();

	  vibrate = ps2x.Analog(PSAB_BLUE);

	  if(ps2x.Button(PSB_PAD_UP))
	  {
	    Gonk.walk(0,900,1); // Andando adelante
	  }

	  else if(ps2x.Button(PSB_PAD_DOWN))
	  {
	    Gonk.walk(0,900,-1); // Andando Atras
	  }

	  else if(ps2x.Button(PSB_PAD_LEFT))
	  {
		  Gonk.turn(0,900,1); // Giro a la izquierda
	  }

	  else if(ps2x.Button(PSB_PAD_RIGHT))
	  {
		  Gonk.turn(0,900,-1); // Giro a la derecha
	  }


	  if(ps2x.ButtonPressed(PSB_BLUE))
	  {
	    Serial.println("Presionaste X: ");
	  }
	  if(ps2x.ButtonPressed(PSB_PINK))
	  {
	    Serial.println("Presionaste cuadrado: ");
	  }
	  if(ps2x.ButtonPressed(PSB_RED))
	  {
	    Serial.println("Presionaste redondo: ");
	  }
	  if(ps2x.ButtonPressed(PSB_GREEN))
	  {
	    Serial.println("Presionaste triangulo: ");
	  }
	  if(ps2x.ButtonPressed(PSB_L1))
	  {
	    Serial.println("Presionaste L1: ");
	  }
	  if(ps2x.ButtonPressed(PSB_L2))
	  {
	    Serial.println("Presionaste L2: ");
	  }
	  if(ps2x.ButtonPressed(PSB_R1))
	  {
	    Serial.println("Presionaste R1: ");
	  }
	  if(ps2x.ButtonPressed(PSB_R2))
	  {
	    Serial.println("Presionaste R2: ");
	  }


	  if(ps2x.ButtonPressed(PSB_SELECT))
	  {
	    Serial.println("Presionaste seleccionar: ");
	  }
	  else if(ps2x.ButtonPressed(PSB_START))
	  {
		  Gonk.home();
		   delay(50);
	  }


	  delay(50);
}
