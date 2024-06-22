//LIBRERIA DTH11 SENSOR DE TEMPERATURA Y HUMEDAD--------------------------------------------------------------------------
#include "DHT.h"
DHT dht(2, DHT11);
const int ZumTemp =  4;
const int LedTemp =  11;

//libreia OLED--------------------------------------------------------------------------------------------------------------

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16

//MAPA DE BITS IMAGEN SENA ---------------------------------------------------------------------------------------------------

 const unsigned char sena [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x03, 0xff, 0x80, 0x1f, 0xff, 0xff, 0x87, 0xff, 0x00, 0x1f, 0xc0, 0x01, 0xff, 0x00, 0x00, 
  0x01, 0xff, 0x01, 0xfe, 0x1f, 0xf0, 0x00, 0x87, 0xff, 0xe0, 0x3f, 0xc0, 0x0f, 0xff, 0xe0, 0x00, 
  0x00, 0xff, 0xff, 0xe0, 0x1f, 0xff, 0xff, 0x07, 0xfb, 0xfc, 0x3f, 0xc0, 0x3f, 0x87, 0xf8, 0x00, 
  0x01, 0x00, 0x01, 0xff, 0x1f, 0xe0, 0x00, 0x07, 0xf8, 0x3f, 0xff, 0xc1, 0xff, 0xff, 0xff, 0x00, 
  0x00, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0x87, 0xf8, 0x07, 0xff, 0xcf, 0xf0, 0x00, 0x3f, 0xe0, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
  0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
  0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xf0, 0x03, 0xc0, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x80, 0x0f, 0xf0, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x0f, 0xfe, 0x00, 0x7f, 0xfc, 0x00, 0x7f, 0xf0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x7f, 0xf8, 0x01, 0xff, 0xff, 0x80, 0x1f, 0xfe, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x01, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xe0, 0x03, 0xff, 0x80, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x07, 0xff, 0x00, 0x1f, 0xf8, 0x1f, 0xfc, 0x00, 0xff, 0xe0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0xff, 0xe0, 0x07, 0xff, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xff, 0xe0, 0x03, 0xff, 0x00, 0x01, 0xff, 0xc0, 0x07, 0xff, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x03, 0xff, 0x80, 0x0f, 0xfc, 0x00, 0x00, 0x3f, 0xf8, 0x01, 0xff, 0xc0, 0x00, 0x00, 
  0x00, 0x00, 0x0f, 0xfe, 0x00, 0x7f, 0xf0, 0x00, 0x00, 0x0f, 0xfe, 0x00, 0x7f, 0xf0, 0x00, 0x00, 
  0x00, 0x00, 0x3f, 0xf0, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xc0, 0x0f, 0xfc, 0x00, 0x00, 
  0x00, 0x00, 0x03, 0xc0, 0x07, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf0, 0x03, 0xc0, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };
  

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


void setup()

//PANTALLA OLED----------------------------------------------------------------------------------------------------------------------------------------
{  
  Serial.begin(9600);
  Serial.println("Prueba del sensor DHT11");
  dht.begin();
  pinMode(ZumTemp, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

}

void loop(){
//SENOSR DTH11 IMPRIME EN LA PANTALLA OLED VALORES-----------------------------------------------------------------------------------------------------

display.display();
display.clearDisplay();
display.drawBitmap(0,0,sena,128,64,WHITE);
display.display();
display.clearDisplay();

{
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
 
  // REVISAR QUE LOS RESULTADOS SEAN VALORES NUMERICOS VALIDOS, INDICANDO QUE LA COMUNICACION ES CORRECTA
  if (isnan(h) || isnan(t)) {
    Serial.println("Falla al leer el sensor DHT11!");
    return;
  }
 
  // IMPRIMIR RESULTADO AL MONITOR SERIAL
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(15,0);
  display.print("TEMPERATURA C");
  display.print(t);
  display.display();
  display.display();
display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20,20);
  display.print("HUMEDAD H");
  display.print(h);
  display.display();
  display.display();
  delay(2000);

if(t>32){ // si la temperatura es mayor a 22 grados celsius se activará la alarma
      digitalWrite(ZumTemp, HIGH);
      delay(700);
      digitalWrite(ZumTemp, LOW);
    }
    else{
      digitalWrite(ZumTemp, LOW);
      }
if(t>32){ // si la temperatura es mayor a 22 grados celsius se activará la alarma
      digitalWrite(LedTemp, HIGH);
      delay(700);
      digitalWrite(LedTemp, LOW);
    }
    else{
      digitalWrite(LedTemp, LOW);
      }
}
 
}
