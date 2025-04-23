/**
* @file ledstrip_ctrl_01
* @brief Controls a LED strip based on WS2812B the chip. The test
* checks the communication with the LED Strip, by powering on the
* LEDS of the strip sequentially.
* @param PIN pin used to communicate with the led strip.
* @param NUMPIXELS number of pixels to power on/off.
* @param DELAYVAL time between led and led PowerOn.
* @param INCREMENTO next led increment.
* @param R Componente rojo
* @param G Componente verde
* @param B Componente azul
* @note The program is designed by Arduino Uno with libs Adafruit_NeoPixel.
* @note The 2 meter x 144 LEDS strip requires 2.5A@5V
*/

#include <Adafruit_NeoPixel.h>

#define MAXLEDS 288
#define INCREMENTO 1
//Designamos nuestro pin de datos
#define PIN 6
//Designamos cuantos pixeles tenemos en nuestra cinta led RGB
#define NUMPIXELS      MAXLEDS
// Color del LED
#define R 125
#define G 150
#define B 0


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 125 // Time (in milliseconds) to pause between pixels

void setup() {
  // put your setup code here, to run once:
  pixels.begin(); 
}

void loop() {
  // put your main code here, to run repeatedly:
  pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i=i+INCREMENTO) { // For each pixel...
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(R, G, B));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }

}
