
#include <BH1750FVI.h> // Sensor Library
#include <Wire.h> // I2C Library
#include <DHT.h>;


#define DHTPIN 5     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

BH1750FVI LightSensor;

int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup() { 
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  LightSensor.begin();
  dht.begin();

  LightSensor.SetAddress(Device_Address_H);//Address 0x5C
  LightSensor.SetMode(Continuous_H_resolution_Mode);

  Serial.println("Running...");
}

uint16_t level = 0;

void showOnSerial(uint16_t luxity, uint16_t level)
{
    if (level == 1) Serial.print("its DARK: ");
    else if (level == 2) Serial.print("its Light: ");
    Serial.print(luxity);
    Serial.println(" lux"); 
}

void loop() {
  digitalWrite(7, HIGH); // зажигаем светодиод
delay(1000); // ждем 1 секунду
    digitalWrite(8, HIGH); // зажигаем светодиод
delay(1000); // ждем 1 секунду
  digitalWrite(9, HIGH); // зажигаем светодиод
delay(1000); // ждем 1 секунду
    digitalWrite(10, HIGH); // зажигаем светодиод
delay(1000); // ждем 1 секунду
  digitalWrite(11, HIGH); // зажигаем светодиод
delay(1000); // ждем 1 секунду
    digitalWrite(12, HIGH); // зажигаем светодиод
delay(1000); // ждем 1 секунду

digitalWrite(7, LOW); // выключаем светодиод
digitalWrite(8, LOW); // выключаем светодиод
digitalWrite(9, LOW); // выключаем светодиод
digitalWrite(10, LOW); // выключаем светодиод
digitalWrite(11, LOW); // выключаем светодиод
digitalWrite(12, LOW); // выключаем светодиод
delay(1000); // ждем 1 секунду
  uint16_t lux = LightSensor.GetLightIntensity();// Get Lux value
  
  
if ( lux <= 0) 
 {
  level = 1;
  showOnSerial(lux, level);
  Serial.print("its DARK: ");
  Serial.print(lux);
  Serial.println(" lux"); 
 }
 else if ( lux <= 100) 
 {
  Serial.print("its Light: ");
  Serial.print(lux);
  Serial.println(" lux"); 
 }
 else if ( lux <= 1000) {
    Serial.print("its very light: ");
  Serial.print(lux);
  Serial.println(" lux"); }
  
  else if ( lux <= 100000) {
    Serial.print("its ultra light: ");
  Serial.print(lux);
  Serial.println(" lux"); }

delay(2000);
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");

    digitalWrite(3, HIGH);
    
    delay(10000); //Delay 2 sec.

    digitalWrite(3, LOW);
}
