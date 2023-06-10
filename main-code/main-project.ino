#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;

#define DHT11_PIN 10
#define RELAY_PIN 2

void setup(){
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT); //set the relay
}

void loop(){
  //604800000s one week
  delay(604800000);
  int i;

  for(i=0; i<1008; i++)
  { //144 = times that will repeat in one day  
    delay(900000); //10min=900000s to the next verification
    DHT.read(DHT11_PIN);
    Serial.print("umidade:");
    Serial.println(DHT.humidity);


    if(DHT.humidity >= 90)
    {
      digitalWrite(RELAY_PIN, HIGH);
      delay(15000);
      digitalWrite(RELAY_PIN, LOW);
    }
  }
}
