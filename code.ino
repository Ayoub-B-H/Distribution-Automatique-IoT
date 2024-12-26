#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"


#define SSID       "put your SSID"
#define Password      "put your Password"
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                  
#define AIO_USERNAME    "put your username"
#define AIO_KEY         "put your key"
// #define led_gpio D4

int led_gpio=2; //D4
int led_gpio1=5; //D1
int led_gpio2=16; //D0
WiFiClient client;    

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);        
//Adafruit_MQTT_Subscribe ESP8266_LED_CONTROL = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/led");
Adafruit_MQTT_Subscribe Manga = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/manga");
Adafruit_MQTT_Subscribe Orange = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/orange");
Adafruit_MQTT_Subscribe Citron = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/citron");

void MQTT_connect();

void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(led_gpio,OUTPUT);
  digitalWrite(led_gpio,HIGH);
    pinMode(led_gpio1,OUTPUT);
  digitalWrite(led_gpio1,HIGH);
    pinMode(led_gpio2,OUTPUT);
  digitalWrite(led_gpio2,HIGH);
  Serial.println(); Serial.println();
  Serial.print("Connecting to WIFI ");
  WiFi.begin(SSID,Password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  mqtt.subscribe(&Manga);
    mqtt.subscribe(&Orange);
      mqtt.subscribe(&Citron);

}
uint32_t x=0;

void loop() {
   MQTT_connect();
Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) {
    if (subscription == &Manga) {
      Serial.print(F("Got: "));
      Serial.println((char *)Manga.lastread);
       if (!strcmp((char*) Manga.lastread, "1"))
      {
        digitalWrite(led_gpio, LOW);
        delay(3000);
        digitalWrite(led_gpio, HIGH);
      }
      else
      {
        digitalWrite(led_gpio, HIGH);

      }
    }
    if (subscription == &Orange) {
      Serial.print(F("Got: "));
      Serial.println((char *)Orange.lastread);
       if (!strcmp((char*) Orange.lastread, "1"))
      {
        digitalWrite(led_gpio1, LOW);
        delay(3000);
        digitalWrite(led_gpio1, HIGH);
      }
      else
      {
        digitalWrite(led_gpio1, HIGH);

      }
    }
    if (subscription == &Citron) {
      Serial.print(F("Got: "));
      Serial.println((char *)Citron.lastread);
       if (!strcmp((char*) Citron.lastread, "1"))
      {
        digitalWrite(led_gpio2, LOW);
        delay(3000);
        digitalWrite(led_gpio2, HIGH);
      }
      else
      {
        digitalWrite(led_gpio2, HIGH);

      }
    }
   
  }
}

void MQTT_connect() {
  int8_t again;
  if (mqtt.connected()) {
    return;
  }
Serial.print("Connecting to Adafruit IO");
uint8_t retry = 5;
  while ((again = mqtt.connect()) != 0) {
       Serial.println(mqtt.connectErrorString(again));
       Serial.println("Retrying Adafruit connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  
       retry--;
       if (retry == 0) {
         while (1);
       }

  }
  Serial.println("");
  Serial.println("Adafruit IO is Connected!");
}
