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

int sensorPin = A0;
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

//Designamos cuantos pixeles tenemos en nuestra cinta led RGB
#define NUMPIXELS      MAXLEDS
// Color del LED
#define R 125
#define G 150
#define B 0

typedef struct led_color_t {
  float distancia_ua;
}led_color_t;

led_color_t led_status[MAXLEDS];
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 1000 // Time (in milliseconds) to pause between pixels
#define MAXSIMULATION_TIME 300 // Minutos de simulation.

#define SUN     287
#define NEPTUNO 38
#define NEPTUNO_DIST 30
#define URANO 65
#define URANO_DIST 19
#define SATURNO 103
#define SATURNO_DIST 9.5
#define JUPITER 117
#define JUPITER_DIST 5.2
#define MARTE 175
#define MARTE_DIST 1.5
#define TIERRA 189
#define TIERRA_DIST 1
#define VENUS 226
#define VENUS_DIST 0.7
#define MERCURIO 235
#define MERCURIO_DIST 0.4

//La Luz recorre 1ua en 500 segundos
float velocidad_desplazamiento;
float distancia_recorrida;
uint32_t t;

void setup() {
  // put your setup code here, to run once:
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);

  pixels.begin();

  //La Luz recorre 1ua en 500 segundos
  velocidad_desplazamiento = 1.0 / 500; //Velocidad en 0.002 ua/s
  distancia_recorrida = 0;  // En unidades astronomicas con 1 decimal o 2.
  t= 0; // simulation time.

  // Prepare the Look-Up table for pixels distance
  for (int i = 0; i < MAXLEDS; i ++)
  {
    if ( i <= NEPTUNO){
      led_status[i].distancia_ua = (SUN - i ) * NEPTUNO_DIST / (SUN - NEPTUNO);
      continue;
    }

    if ( i <= URANO){
      led_status[i].distancia_ua = (SUN - i ) * URANO_DIST / (SUN - URANO);
      continue;
    }

    if ( i <= SATURNO){
      led_status[i].distancia_ua = (SUN - i ) * SATURNO_DIST / (SUN - SATURNO);
      continue;
    }

    if ( i <= JUPITER){
      led_status[i].distancia_ua = (SUN - i ) * JUPITER_DIST / (SUN - JUPITER);
      continue;
    }

    if ( i <= MARTE){
      led_status[i].distancia_ua = (SUN - i ) * MARTE_DIST / (SUN - MARTE);
      continue;
    }

    if ( i <= TIERRA){
      led_status[i].distancia_ua = (SUN - i ) * TIERRA_DIST / (SUN - TIERRA);
      continue;
    }

    if ( i <= VENUS){
      led_status[i].distancia_ua = (SUN - i ) * VENUS_DIST / (SUN - VENUS);
      continue;
    }

    if ( i <= MERCURIO){
      led_status[i].distancia_ua = (SUN - i ) * MERCURIO_DIST / (SUN - MERCURIO);
      continue;
    }


    led_status[i].distancia_ua = 0;

  }
}

void loop() {

  int ligth_time_counter = 0;
  // put your main code here, to run repeatedly:
  pixels.clear(); // Set all pixel colors to 'off'

// Main simulation
  while ( distancia_recorrida <  32){
      // read the value from the sensor:
    sensorValue = analogRead(sensorPin);
    // turn the ledPin on
    digitalWrite(ledPin, HIGH);

    distancia_recorrida = t * (velocidad_desplazamiento);
    // Vamos a ir cambiando la velocidad de desplazamiento 
    // cuando lleguemos al planeta.

    for( int led = 0; led < NUMPIXELS; led ++)  // Actualizamos el estado de los leds.
    {
      if (led_status[led].distancia_ua <=  distancia_recorrida)
        if ( (led == MERCURIO) || (led == VENUS) || (led == TIERRA) || (led == MARTE) ||
          (led == JUPITER) || (led == SATURNO) || (led == URANO) || (led == NEPTUNO) )
                pixels.setPixelColor(led, pixels.Color(0, 128, 32));
        else
                pixels.setPixelColor(led, pixels.Color(255, 0, 0));

    }


    // Siguiente iteracion
    t++;
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL-sensorValue); // Pause before next pass through loop
      // turn the ledPin off:
    digitalWrite(ledPin, LOW);
  }

  distancia_recorrida = 0;        

}
