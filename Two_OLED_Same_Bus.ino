/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x64 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display2(OLED_RESET);
Adafruit_SSD1306 display1(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
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
  B00000000, B00110000
};

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display1.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display2.begin(SSD1306_SWITCHCAPVCC, 0x3D);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display2.display();
  display1.display();
  delay(2000);
  display2.clearDisplay();
  display1.clearDisplay();
}


void loop() {

  display1.setTextSize(2);
  display1.setTextColor(WHITE);
  display1.setCursor(10, 0);
  display1.clearDisplay();
  display1.println("Test Left");
  display1.display();
  delay(2000);
  display1.clearDisplay();

  display2.setTextSize(3);
  display2.setTextColor(WHITE);
  display2.setCursor(10, 0);
  display2.clearDisplay();
  display2.setCursor(10, 0);
  display2.println("Test");
  display2.setCursor(10, 30);
  display2.println("Right");
  display2.display();
  delay(2000);
  display2.clearDisplay();

  display2.setTextSize(2);
  display2.setTextColor(WHITE);
  display2.clearDisplay();
  display1.setCursor(10, 0);
  display1.println("Test");
  display1.setCursor(10, 20);
  display1.println("Right");
  display2.display();
  delay(2000);
  display2.clearDisplay();

  display1.setTextSize(3);
  display1.setTextColor(WHITE);
  display1.setCursor(10, 0);
  display1.clearDisplay();
  display1.setCursor(10, 0);
  display1.println("Test");
  display1.setCursor(10, 30);
  display1.println("Left");
  display1.display();
  delay(2000);
  display1.clearDisplay();

}



