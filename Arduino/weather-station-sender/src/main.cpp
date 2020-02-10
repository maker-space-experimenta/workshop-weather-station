#include <Arduino.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <avr/sleep.h>
#include <avr/power.h>

#define DHTPIN 2
#define DHTTYPE DHT22

volatile int toggle = 0;

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
int button_pin = 2;
boolean button_state = 0;

int maxHum = 60;
int maxTemp = 40;

DHT dht(DHTPIN, DHTTYPE);

ISR(TIMER1_OVF_vect)
/* Timer1 Interrupt service Routine */
{
  if (toggle == 0)
    toggle = 1;
}

void enter_sleep(void)
/* Arduino schlafen legen */
{
  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_enable();

  /* Weil diesmal nicht der tiefste Schlafmodus gewaehlt wurde,
   * koennen unbenutzte Komponenten noch zusaetzlich abgeschaltet
   * werden, um Energie zu sparen. Noch wichtiger: Die Komponenten
   * koennten ggf. den Arduino ungewollt aufwecken.
   */
  power_adc_disable();    /* Analog-Eingaenge abschalten */
  power_spi_disable();    /* SPI abschalten */
  power_timer0_disable(); /* Timer0 abschalten */
  power_timer2_disable(); /* Timer0 abschalten */
  power_twi_disable();    /* TWI abschalten */

  sleep_mode();
  sleep_disable();

  power_all_enable(); /* Komponenten wieder aktivieren */
}

void setup()
{
  Serial.begin(9600);

  /* Timer konfigurieren */
  TCCR1A = 0x00; /* Normalbetrieb /*
  TCNT1 = 0x0000; /* Zaehler loeschen */
  TCCR1B = 0x05; /* Prescaler: 1024 */
  TIMSK1 = 0x01; /* Timer-Interrupt einschalten */

  dht.begin();

  radio.begin();                  //Starting the Wireless communication
  radio.openWritingPipe(address); //Setting the address where we will send the data
  radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.stopListening();
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("h: ");
  Serial.println(h);
  Serial.print("t: ");
  Serial.println(t);

  char text[] = "00.00;00:00";
  String s = String(h);
  s.concat(";");
  s.concat(String(t));
  s.toCharArray(text, sizeof(text));

  Serial.println(sizeof(text));
  Serial.println(text);
  radio.write(&text, sizeof(text));
  delay(1000);

  enter_sleep();
}