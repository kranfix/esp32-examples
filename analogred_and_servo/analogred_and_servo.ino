int freq = 50; // Hz for PWM
int bits = 12;  // bits of resolution

int readPin = 13;
int servoPin = 12;
int servoChannel = 1;

void setup() {
  Serial.begin(9600);
  
  ledcAttachPin(servoPin, servoChannel);
  ledcSetup(servoChannel, freq, bits);
} 

void loop() {
  int val = analogRead(readPin); // top left  
  ledcWrite(servoChannel, val);
  Serial.println(val);
}

