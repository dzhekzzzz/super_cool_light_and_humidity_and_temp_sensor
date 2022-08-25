
#include <BH1750FVI.h> // Sensor Library
#include <Wire.h> // I2C Library

BH1750FVI LightSensor;

void setup() {  
   Serial.begin(9600);
  LightSensor.begin();
  LightSensor.SetAddress(Device_Address_H);//Address 0x5C
  LightSensor.SetMode(Continuous_H_resolution_Mode);
  Serial.println("Running...");
}

void loop() {

  uint16_t lux = LightSensor.GetLightIntensity();// Get Lux value
if ( lux <= 0) 
 {
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

 
  
  delay(1000);
}
