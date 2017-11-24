// LDR pin connections
// name = analogpin;
const int ldr1 = 34;
const int ldr2 = 35;
const int ldr3 = 32;

void setup(){
  Serial.begin(9600);
  pinMode(ldr1,INPUT);
  pinMode(ldr2,INPUT);
  pinMode(ldr3,INPUT);
}

void loop(){
  int lx1 = analogRead(ldr1);
  int lx2 = analogRead(ldr2);
  int lx3 = analogRead(ldr3);
  Serial.print("ldr1=");
  Serial.print(lx1);
  Serial.print("\tldr2=");
  Serial.print(lx2);
  Serial.print("\tldr3=");
  Serial.println(lx3);
  
  delay(500);
} 
