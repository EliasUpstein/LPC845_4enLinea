#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

SoftwareSerial SerialSoft(2, 3); // RX, TX

#define PIN        6
#define NUMPIXELS 64

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define ROJO pixels.Color(INTENSIDAD, 0, 0)
#define VERDE pixels.Color(0, INTENSIDAD, 0)
#define AZUL pixels.Color(0, 0, INTENSIDAD)
#define AMARILLO pixels.Color(INTENSIDAD, INTENSIDAD, 0)
#define ROSA pixels.Color(INTENSIDAD, 0, INTENSIDAD)
#define CELESTE pixels.Color(0, INTENSIDAD, INTENSIDAD)
#define BLANCO pixels.Color(INTENSIDAD, INTENSIDAD, INTENSIDAD)
#define OFF pixels.Color(0, 0, 0)


enum {LED, COLOR};

int estado = LED;

uint8_t n_led = 0;
uint32_t color = 0;
uint8_t intensidad = 70;
uint8_t r;
uint8_t g;
uint8_t b;

void setup()
{
  Serial.begin(9600);
  SerialSoft.begin(9600);
  
  pixels.begin();
  pixels.clear();
  pixels.show();
}

void loop() {
  
  switch(estado)
  {
    case LED:
    	if (SerialSoft.available() > 0)
      {
        //n_led = SerialSoft.read() - 33;
        n_led = SerialSoft.read();
        Serial.println(n_led);

        //Si recibe "z" apaga la matriz
        if(n_led == 122)
        {
          pixels.clear();
          pixels.show();
        }//Si recibe "y" prende todo en el mismo color
        else if (n_led == 121) 
        {
          pixels.fill(color, 0, 0);
          pixels.show();
        }//En cualquier otro caso maneja un único led
        else 
          estado = COLOR;
      }
    break;
    case COLOR:
    	if (SerialSoft.available() > 0)
      {
        uint8_t aux = SerialSoft.read();
        Serial.println(aux);
        switch(aux)
        {
          case 0: 		//G
            r = 0;
            g = intensidad;
            b = 0;
          break;
          case 1: 		//B
            r = 0;
            g = 0;
            b = intensidad;
          break;
          case 2: 		//G
            r = 0;
            g = intensidad;
            b = 0;
          break;
          case 3: 		//B
            r = 0;
            g = 0;
            b = intensidad;
          break;
          case 4: 		//G
            r = 0;
            g = intensidad;
            b = intensidad;
          break;
          case 5: 		//B
            r = intensidad;
            g = 0;
            b = intensidad;
          break;
          case 82: 		//R
            r = intensidad;
            g = 0;
            b = 0;
          break;
          case 71: 		//G
            r = 0;
            g = intensidad;
            b = 0;
          break;
          case 66: 		//B
            r = 0;
            g = 0;
            b = intensidad;
          break;
          case 89: 		//Y
            r = intensidad;
            g = intensidad;
            b = 0;
          break;
          case 80: 		//P
            r = intensidad;
            g = 0;
            b = intensidad;
          break;
          case 76: 		//L
            r = 0;
            g = intensidad;
            b = intensidad;
          break;
          case 87: 		//W
            r = intensidad;
            g = intensidad;
            b = intensidad;
          break;
          default:
            r = 0;
            g = 0;
            b = 0;
        }
        
        color = (r << 16) | (g << 8) | (b);
        pixels.setPixelColor(n_led, color);
	      pixels.show();
          
        estado = LED;
      }
    break;
    default:
    	estado = LED;
    break;
  }
}