#include "DHT.h"

#define DHTPIN 2         
#define DHTTYPE DHT22 
#define LEDPIN 13      

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  pinMode(LEDPIN, OUTPUT); 
  dht.begin();            
}

void loop() {
  delay(2000);  

  float humidity = dht.readHumidity();         
  float temperature = dht.readTemperature();   


  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    digitalWrite(LEDPIN, LOW);
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(temperature);
  Serial.println(F("°C"));


  if (humidity > 80.0) {
    digitalWrite(LEDPIN, HIGH);   
    Serial.println("LED ON (Humidity HIGH)");
    delay(3000);                 
    digitalWrite(LEDPIN, LOW);     
  } else {
    digitalWrite(LEDPIN, LOW);      
    Serial.println("LED OFF (Humidity Normal)");
  }
}
