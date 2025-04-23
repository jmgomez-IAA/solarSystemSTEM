/**
* @file lightSpeed_01.ino
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
  // put your main code here, to run repeatedly:
  pixels.clear(); // Set all pixel colors to 'off'

  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...    
    // If Space color yellow
    //for(int j= 0; j < 9; ++j){
      if ( (i == 3) || (i == 6) || ( i == 8) || (i == 12) || ( i ==43) || 
          (i == 79) || (i == 159) || ( i == 250) || (i == 280) ){
        pixels.setPixelColor(i, pixels.Color(250, 0, 0));
      }
      else
      {
        pixels.setPixelColor(i, pixels.Color(0, 125, 2));
      }
    //}
    

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }

}
