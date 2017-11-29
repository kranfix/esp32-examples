#include <Wire.h>
#include <Adafruit_MLX90614.h>
 
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
 
void setup(){
  Serial.begin(9600);
  mlx.begin();
}
 
void loop(){
  // Ambient temperature 
  Serial.print("Ambient:\t");
  Serial.print(mlx.readAmbientTempC());
  Serial.print("°C\t");
  Serial.print(mlx.readAmbientTempF());
  Serial.println("°F");

  // Object temperature
  Serial.print("Object:\t");
  Serial.print(mlx.readObjectTempC());
  Serial.print("°C\t");
  Serial.print(mlx.readObjectTempF());
  Serial.println("°F");
   
  Serial.println();
  delay(1000);
}
