#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define RELAY_PIN 13
#define DHTTYPE DHT22
DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup(){
  Serial.begin(9600);

  dht.begin();
  Serial.println(F("DHTxx Unified Sensor Example"));
  
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);

  pinMode(RELAY_PIN, OUTPUT); //set the relay

  delayMS = sensor.min_delay / 10000;

}

void loop(){

  //START PROGRAM
  delay(delayMS);
  Serial.print(F("STARTING THE PROGRAM :D"));

  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }

  //START FIRST CICLE
  //604800000s one week
  Serial.print(F("START FIRST WEEK"))
  delay(604800000);

  //START SECOND CICLE
  int i;
  for(i=0; i<1008; i++)
  { //144 = times that will repeat in one day  
    delay(900000); //10min=900000s to the next verification

    dht.temperature().getEvent(&event);
    if (isnan(event.temperature)) {
      Serial.println(F("Error reading temperature!"));
    }
    else {
      Serial.print(F("Temperature: "));
      Serial.print(event.temperature);
      Serial.println(F("°C"));
    }
    // Get humidity event and print its value.
    dht.humidity().getEvent(&event);
    if (isnan(event.relative_humidity)) {
      Serial.println(F("Error reading humidity!"));
    }
    else {
      Serial.print(F("Humidity: "));
      Serial.print(event.relative_humidity);
      Serial.println(F("%"));
    }

    if(event.relative_humidity >= 90)
    {
      digitalWrite(RELAY_PIN, HIGH);
      delay(15000);
      digitalWrite(RELAY_PIN, LOW);
    }
  }
}
