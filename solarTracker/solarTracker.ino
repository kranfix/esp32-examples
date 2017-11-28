#include "solarTracker.h"

solarTracker_t st = {
  { // servo Pin
    18, // Azimut servo pin
    19  // Polar servo pin
  },
  { // servo channels
    1, // Channel for azimut servo
    2  // Channel for polar servo
  },
  { // LDR Pin
   32, // Top-left LDR pin
   33, // Top-Right LDR Pi  n
   2,  // Down-left LDR pin 
   4   // Down-Right LDR Pin
  }
};

void setup(){
  Serial.begin(9600);
  solarTracker_begin(&st);
}

void loop(){
  /*for(st.servoVal.azimut = 0; st.servoVal.azimut < 30; st.servoVal.azimut++){
    solarTracker_loop(&st);
    delay(500);
  }
  for( ; st.servoVal.azimut > 0; st.servoVal.azimut--){
    solarTracker_loop(&st);
    delay(500);
  }*/
  solarTracker_loop(&st);
  delay(10);
}
