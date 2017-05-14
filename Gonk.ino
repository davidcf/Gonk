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
#include "SoftwareSerial.h"
#include "BatReader.h"
#include <Vcc.h>

//Bateria
const float VccMin   = 0.0;           // Minimum expected Vcc level, in Volts.
const float VccMax   = 5.0;           // Maximum expected Vcc level, in Volts.
const float VccCorrection = 1.0/1.0;  // Measured Vcc by multimeter divided by reported Vcc
Vcc vcc(VccCorrection);

String TextoLCD = "";
String TextoVcc = "";
String TextoPer = "";
int speakerPin = 10;

PS2X ps2x;
BatReader batreader;

int error = 0;
byte vibrate = 0;

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

//Declaracion de Variables
const int LOGLEVEL = 1; // 1 activa trazas de log en serial, 0 Desactiva trazas
const int SOUND    = 0; // 1 activa sonidos, 0 los desactiva

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
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);


//Inicializamos joystick
  display.clearDisplay();
  WriteLCD("Initializing....",0,0,0,"NO");
  delay (1000);
  ps2x.config_gamepad(8,11,A1,9,true,true); //(clock, command, attention, data)
  WriteLCD("Gamepad....OK",0,0,9,"NO");



//Inicializamos Gonk
  WriteLCD("Central....OK",0,0,17,"NO");
  Gonk.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR,true);
  //PONER SONIDO DE INICIALIZACION
  Gonk.home();
  if (SOUND == 1) Gonk.sing(S_connection);
  delay(1000);

//Mensaje final
  WriteLCD(" Ready",3,0,0,"SI");
}

void loop() {

//Gonk.sing(S_sleeping);


//Serial.println(GetTemp(),1);
//delay(500);
GamePad();

//GameJoystick();
//Gonk.sing(S_buttonPushed);
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
void WriteLCD(String Text, int tamano, int linea, int columna,String Borrado)      // Escritura de una linea en LCD
{
	if (Borrado == "SI") display.clearDisplay();

	  display.setTextSize(tamano);
	  display.setTextColor(WHITE);
	  display.setCursor(linea,columna);
	  display.println(Text);
	  //display.println("Hace mucho tiempo en ");
	  //display.setCursor(0,8);
	  //display.println("una galaxia muy muy ");
	  //display.setCursor(0,16);
	  //display.println("lejana...");
	  display.display();
	  delay(200);
	  if (Borrado == "SI") display.clearDisplay();
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

	    //Gonk.sing(S_connection); //OK
	    //Gonk.sing(S_disconnection); //OK
	    //Gonk.sing(S_buttonPushed);
	    //Gonk.sing(S_mode1);
	    //Gonk.sing(S_mode2);
	    //Gonk.sing(S_mode3);
	    //Gonk.sing(S_surprise);
	    //Gonk.sing(S_OhOoh);
	    //Gonk.sing(S_OhOoh2);
	    //Gonk.sing(S_cuddly);
	    //Gonk.sing(S_sleeping);
	    //Gonk.sing(S_happy);
	    //Gonk.sing(S_superHappy);
	    //Gonk.sing(S_happy_short);
	    //Gonk.sing(S_sad);
	    //Gonk.sing(S_confused);
	    //Gonk.sing(S_fart1);
	    //Gonk.sing(S_fart2);
	    //Gonk.sing(S_fart3);
	  }
	  if(ps2x.ButtonPressed(PSB_PINK))
	  {
	    Serial.println("Presionaste cuadrado: ");
	      //squeak(); //Arranque
	      //catcall(); //Fifiu fifiu
	      //ohhh(); //Objeto en camino
	      //laugh(); //Cuando anda?????
	    //scale();
	      //closeEncounters();
	      //closeEncounters1();
	      //closeEncounters2();
	      //laugh2();
	      //waka();
	      //r2D2();
	      //ariel();
	    if (SOUND == 1) uhoh();
	    //Gonk.sing(S_connection); //OK
	    //Gonk.sing(S_disconnection); //OK
	    //Gonk.sing(S_buttonPushed);
	    //Gonk.sing(S_mode1);
	    //Gonk.sing(S_mode2);
	    //Gonk.sing(S_mode3);
	    //Gonk.sing(S_surprise);
	    //Gonk.sing(S_OhOoh);
	    //Gonk.sing(S_OhOoh2);
	    //Gonk.sing(S_cuddly);
	    //Gonk.sing(S_sleeping);
	    //Gonk.sing(S_happy);
	    //Gonk.sing(S_superHappy);
	    //Gonk.sing(S_happy_short);
	    //Gonk.sing(S_sad);
	    //Gonk.sing(S_confused);
	    //Gonk.sing(S_fart1);
	    //Gonk.sing(S_fart2);
	    //Gonk.sing(S_fart3);
	  }
	  if(ps2x.ButtonPressed(PSB_RED))
	  {
	    Serial.println("Presionaste redondo: ");
	  }
	  if(ps2x.ButtonPressed(PSB_GREEN))
	  {
		  float v = vcc.Read_Volts();
		  float p = vcc.Read_Perc(VccMin, VccMax);
		  TextoVcc = v;
		  TextoPer = p;
		  WriteLCD("---------------------",0,0,0,"NO");
		  WriteLCD("---------------------",0,0,24,"NO");
		  WriteLCD("Battery Voltage: "+TextoVcc,0,0,8,"NO");

		    if (p > 80.00){
		      WriteLCD("Battery Level:"+TextoPer+"%",0,0,17,"NO");
		  	  if (SOUND == 1) Gonk.sing(S_batteri100);
		    }

		    if (p < 50.00){
			  WriteLCD("Battery Level:"+TextoPer+"%",0,0,17,"NO");
		  	  if (SOUND == 1) Gonk.sing(S_batteri50);
		    }

		    if (p < 10.00){
			  WriteLCD("Battery Level:"+TextoPer+"%",0,0,17,"NO");
		  	  if (SOUND == 1) Gonk.sing(S_batteri0);
		    }

		    delay (2000);

		    WriteLCD(" Ready",3,0,0,"SI");

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
		  if (SOUND == 1) Gonk.sing(S_connection);
		  Gonk.home();
		  delay(50);
	  }


	  delay(50);
}


void beep (int speakerPin, float noteFrequency, long noteDuration)
{
  int x;
  // Convert the frequency to microseconds
  float microsecondsPerWave = 1000000/noteFrequency;
  // Calculate how many HIGH/LOW cycles there are per millisecond
  float millisecondsPerCycle = 1000/(microsecondsPerWave * 2);
  // Multiply noteDuration * number or cycles per millisecond
  float loopTime = noteDuration * millisecondsPerCycle;
  // Play the note for the calculated loopTime.
  for (x=0;x<loopTime;x++)
          {
              digitalWrite(speakerPin,HIGH);
              delayMicroseconds(microsecondsPerWave);
              digitalWrite(speakerPin,LOW);
              delayMicroseconds(microsecondsPerWave);
          }
}

void scale()
{
          beep(speakerPin, note_C7,500); //C: play the note C for 500ms
          beep(speakerPin, note_D7,500); //D
          beep(speakerPin, note_E7,500); //E
          beep(speakerPin, note_F7,500); //F
          beep(speakerPin, note_G7,500); //G
          beep(speakerPin, note_A7,500); //A
          beep(speakerPin, note_B7,500); //B
          beep(speakerPin, note_C8,500); //C
}



void laugh2() {
          beep(speakerPin, note_C6,200); //C
          beep(speakerPin, note_E6,200); //E
          beep(speakerPin, note_G6,200); //G
          beep(speakerPin, note_C7,200); //C
          beep(speakerPin, note_C6,200); //C
          delay(50);
          beep(speakerPin, note_C6,200); //C
          beep(speakerPin, note_E6,200); //E
          beep(speakerPin, note_G6,200); //G
          beep(speakerPin, note_C7,200); //C
          beep(speakerPin, note_C6,200); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C



}

void squeak() {
  for (int i=100; i<5000; i=i*1.45) {
    beep(speakerPin,i,60);
  }
  delay(10);
  for (int i=100; i<6000; i=i*1.5) {
    beep(speakerPin,i,20);
  }
}

void waka() {
  for (int i=1000; i<3000; i=i*1.05) {
    beep(speakerPin,i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    beep(speakerPin,i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    beep(speakerPin,i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    beep(speakerPin,i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    beep(speakerPin,i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    beep(speakerPin,i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    beep(speakerPin,i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    beep(speakerPin,i,10);
  }
}

void catcall() {
  for (int i=1000; i<5000; i=i*1.05) {
    beep(speakerPin,i,10);
  }
 delay(300);

  for (int i=1000; i<3000; i=i*1.03) {
    beep(speakerPin,i,10);
  }
  for (int i=3000; i>1000; i=i*.97) {
    beep(speakerPin,i,10);
  }
}

void ohhh() {
  for (int i=1000; i<2000; i=i*1.02) {
    beep(speakerPin,i,10);
  }
  for (int i=2000; i>1000; i=i*.98) {
    beep(speakerPin,i,10);
  }
}

void uhoh() {
  for (int i=1000; i<1244; i=i*1.01) {
    beep(speakerPin,i,30);
  }
  delay(200);
  for (int i=1244; i>1108; i=i*.99) {
    beep(speakerPin,i,30);
  }
}

void laugh() {
  for (int i=1000; i<2000; i=i*1.10) {
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i<2000; i=i*1.10) {
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(speakerPin,i,10);
  }
  delay(50);
    for (int i=1000; i<2000; i=i*1.10) {
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(speakerPin,i,10);
  }
  delay(50);
    for (int i=1000; i<2000; i=i*1.10) {
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(speakerPin,i,10);
  }
  delay(50);
}
