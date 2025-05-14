/**
* @file cartel_sistema_solar.ino
* @brief STEM resource describing the time requiered to cross 
* the solar system at the speed of light.
* @param PIN pin used to communicate with the led strip.
* @param NUMPIXELS number of pixels to power on/off.
* @param MAXTIME time to reach the end of the strip.
* @param LENGTH length of the strip.
* @param R Componente rojo
* @param G Componente verde
* @param B Componente azul
* @note The program is designed by Arduino Uno with libs Adafruit_NeoPixel.
* @note The 2 meter x 144 LEDS strip requires 2.5A@5V
*/

#include <Adafruit_NeoPixel.h>

#define MAXLEDS 288
//Designamos nuestro pin de datos
#define PIN 6
//Designamos cuantos pixeles tenemos en nuestra cinta led RGB
#define NUMPIXELS      MAXLEDS
// Color del LED
#define R 125
#define G 150
#define B 0

const double light_speed = 300000;  //km/s
const double un_km = 149597870; // km
float astros_distance_cm[] = {2.6, 4.8, 6.7, 10.1, 34.7, 63.6, 127.9, 200};
int tiempos_planetas[] = {3, 6, 8, 12, 43, 79, 159, 250, 328};


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 1000 // Time (in milliseconds) to pause between pixels

void setup() {
  // put your setup code here, to run once:
  pixels.begin(); 
}

void loop() {

  int ligth_time_counter = 0;
  // put your main code here, to run repeatedly:
  pixels.clear(); // Set all pixel colors to 'off'

  for( int time = 0; time < NUMPIXELS; time ++)  // 360 seguntos = 6 minutos
  {
    switch( time )
    {
      case 3:   // Mercurio
          pixels.setPixelColor(72+72+72+19, pixels.Color(250, 0, 0));
        break;
      case 6:   // Venus
          pixels.setPixelColor(72+72+72+10, pixels.Color(250, 0, 0));
        break;
      case 8:   // Tierra
          pixels.setPixelColor(72+72+45, pixels.Color(250, 0, 0));
        break;
      case 12:   // Marte
          pixels.setPixelColor(72+72+31, pixels.Color(250, 0, 0));
        break;
      case 43:   // Jupiter
          pixels.setPixelColor(72+45, pixels.Color(250, 0, 0));
        break;
      case 79:   // Saturno
          pixels.setPixelColor(72+31, pixels.Color(250, 0, 0));
        break;
      case 160:   // Urano
          pixels.setPixelColor(65, pixels.Color(250, 0, 0));
        break;
      case 250:   // Neptuno
          pixels.setPixelColor(38, pixels.Color(250, 0, 0));
        break;
      default:
          pixels.setPixelColor(NUMPIXELS-time, pixels.Color(0, 125, 2));
    }

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop

  }

}
