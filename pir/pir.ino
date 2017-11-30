/* Author: Frank Moreno (kranfix)
 */

const int LedPin = 2;  // LED_BUILTIN
const int PirPin = 12;
 
int pirState = LOW;
int val = LOW;
 
void setup() 
{
  Serial.begin(9600);
  pinMode(LedPin, OUTPUT); 
  pinMode(PirPin, INPUT);
}
 
void loop()
{
  val = digitalRead(PirPin);
  digitalWrite(LedPin, val);
  if (val != pirState){ 
    if (pirState == LOW){
      Serial.println("Sensor activado");
    } else {
      Serial.println("Sensor parado");
    }
    pirState = val;
  }
  delay(20);
}
