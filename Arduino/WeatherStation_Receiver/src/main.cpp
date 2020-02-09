/*********
  Complete project details at https://randomnerdtutorials.com
  
  This is an example for our Monochrome OLEDs based on SSD1306 drivers. Pick one up today in the adafruit shop! ------> http://www.adafruit.com/category/63_98
  This example is for a 128x32 pixel display using I2C to communicate 3 pins are required to interface (two I2C and one reset).
  Adafruit invests time and resources providing this open source code, please support Adafruit and open-source hardware by purchasing products from Adafruit!
  Written by Limor Fried/Ladyada for Adafruit Industries, with contributions from the open source community. BSD license, check license.txt for more information All text above, and the splash screen below must be included in any redistribution. 
*********/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <images.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int temperature = -15;
int cursorRow = 30;
unsigned long last = 0;

void renderTemperature(void)
{
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(20, 0);
  display.print("Temperatur");

  display.setTextSize(4);
  display.setTextColor(WHITE);

  if (temperature < -9)
  {
    display.setCursor(8, cursorRow);
  }
  else if (temperature < 0)
  {
    display.setCursor(22, cursorRow);
  }
  else if (temperature < 10)
  {
    display.setCursor(46, cursorRow);
  }
  else
  {
    display.setCursor(22, cursorRow);
  }

  display.print(temperature);

  display.print((char)176);
  display.print(F("C"));
  display.display(); // Show initial text
}

void setup()
{
  Serial.begin(115200);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }


  display.clearDisplay();
  display.drawBitmap(0, 0, logoMakerSpace, 128, 64, WHITE);
  display.display();
  delay(2000);
  
  display.clearDisplay();
  display.drawBitmap(0, 0, logoExperimenta, 128, 64, WHITE);
  display.display();
  delay(2000);
  
  display.clearDisplay();
  display.drawBitmap(0, 0, logoExperimentaClaim, 128, 64, WHITE);
  display.display();
  delay(2000);

  // Clear the buffer
  display.clearDisplay();
  display.display();
  delay(2000);
}

void loop()
{

  Serial.println(millis());

  if (last < millis() - 1000)
  {
    last = millis();
    temperature++;
    // renderTemperature();

    display.clearDisplay();

    display.setTextSize(1);
    display.setCursor(20, 0);

    for (int i = 0; i < 256; i++)
    {
      display.print((char)i);
      display.display();
    }
  }
}