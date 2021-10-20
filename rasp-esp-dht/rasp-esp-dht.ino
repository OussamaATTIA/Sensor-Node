

//.......................................LIBRAIRES.......................................//
#include <ESP8266WiFi.h>
#include <DHT.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>  
#include <Wire.h>
//.......................................FIN LIBRAIRES.......................................//

//.......................................VARIABLES.......................................//
#define DHTPIN 4
#define DHTTYPE DHT11

char* ssid = "Rasp-Fire"; //nom réseau
const char* password = "Hephaistos"; //MOT DE PASSE
const char* mqtt_server = "192.168.137.1"; //indiquez l'adresse IP ordinateur

//.......................................FIN VARIABLES.......................................//

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  dht.begin();

   WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connecte");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  
  float t = dht.readTemperature();
  
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
}
