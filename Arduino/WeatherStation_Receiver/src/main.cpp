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

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <images.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String temperature = "-15,00";
String humidity = "00,00";
int cursorRow = 30;
unsigned long lastReceived = 0;

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
boolean button_state = 0;
int led_pin = 3;

void showSplashscreen(void)
{
  display.clearDisplay();
  display.drawBitmap(0, 0, logoMakerSpace, 128, 64, WHITE);
  display.display();
  delay(2000);

  // display.clearDisplay();
  // display.drawBitmap(0, 0, logoExperimenta, 128, 64, WHITE);
  // display.display();
  // delay(2000);

  display.clearDisplay();
  display.drawBitmap(0, 0, logoExperimentaClaim, 128, 64, WHITE);
  display.display();
  delay(2000);

  // Clear the buffer
  display.clearDisplay();
  display.display();
  delay(500);
}

void renderTemperature(void)
{
  display.clearDisplay();
  display.setTextColor(WHITE);

  display.setTextSize(1);
  display.setCursor(10, 0);
  display.print("Luftfeuchte:");
  display.print(humidity);
  display.print("%");

  display.setTextSize(3);

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

  display.setCursor(100, cursorRow - 10);
  display.setTextSize(2);
  display.print((char)247);
  display.print(F("C"));
}

void renderFace(void)
{
  display.clearDisplay();
  display.drawBitmap(0, 0, faceEyeOpen, 128, 64, WHITE);
  display.display();
  delay(2000);

  display.clearDisplay();
  display.drawBitmap(0, 0, faceEyeClosed, 128, 64, WHITE);
  delay(100);
}

void renderMissingLink(void)
{
  display.clearDisplay();
  display.drawBitmap(0, 0, iconMissingLink, 128, 64, WHITE);

  display.setCursor(65, 20);
  display.print("Verbindung");
  display.setCursor(65, 30);
  display.print("verloren");
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

  showSplashscreen();

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(10, 10);
  display.println("Starting radio ...");
  display.display();
  delay(200);
  display.setCursor(10, 30);
  display.println("waiting for first");
  display.setCursor(13, 40);
  display.println("transmittion ...");
  display.display();

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  delay(1000);
}

void loop()
{

  if (radio.available()) //Looking for the data.
  {
    lastReceived = millis();

    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);

    String s = String(text);
    humidity = s.substring(0, 5);
    temperature = s.substring(6);
  }

  Serial.println(millis() - lastReceived);

  if (millis() - lastReceived > 20000)
  {
    renderMissingLink();
  }
  else
  {

    renderTemperature();

    display.setTextSize(1);
    display.setCursor(10, 53);
    display.print("Update vor ");
    int sec = (millis() - lastReceived) / 1000;
    display.print(sec);
    display.print(" Sek");
  }

  display.display();
  delay(5);
}