#include "solarTracker.h"
#include <Arduino.h>

const int lowerThreshold = 0 * 256 / 20;
const int upperThreshold = 3.5 * 256 / 20;
const int middle = (lowerThreshold + upperThreshold) / 2;

const int tol = 300; // tolerance

void solarTracker_begin(solarTracker_t * st){
  ledcAttachPin(st->servoPin.azimut, st->servoChannel.azimut);
  ledcAttachPin(st->servoPin.polar,  st->servoChannel.polar);

  ledcSetup(st->servoChannel.azimut, 50, 8); // 50Hz PWM, 8-bit resolution
  ledcSetup(st->servoChannel.polar, 50, 8);  // 50Hz PWM, 8-bit resolution

  st->servoVal.azimut = middle;
  st->servoVal.polar  = middle;

  ledcWrite(st->servoChannel.azimut, st->servoVal.azimut);
  ledcWrite(st->servoChannel.polar,  st->servoVal.polar);
}

int n = 0;
void solarTracker_loop(solarTracker_t * st) {
  int lt = analogRead(st->ldrPin.lt); // top left
  int rt = analogRead(st->ldrPin.rt); // top right
  int ld = analogRead(st->ldrPin.ld); // down left
  int rd = analogRead(st->ldrPin.rd); // down right

  int avt = (lt + rt) / 2; // average value top
  int avd = (ld + rd) / 2; // average value down
  int avl = (lt + ld) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right

  if (avl > avr + tol && st->servoVal.azimut < upperThreshold){
    st->servoVal.azimut++;
  } else if (avl + tol < avr && st->servoVal.azimut > lowerThreshold) {
    st->servoVal.azimut--;
  }
  ledcWrite(st->servoChannel.azimut, st->servoVal.azimut);

  if (avt > avd + tol && st->servoVal.polar > lowerThreshold){
    st->servoVal.polar--;
  } else if (avt + tol < avd && st->servoVal.polar < upperThreshold){
    st->servoVal.polar++;
  }
  ledcWrite(st->servoChannel.polar, st->servoVal.polar);

  n++;
  if(n == 30){
    n = 0;
    Serial.print("lt=");      Serial.print(lt);
    Serial.print("\trt=");    Serial.println(rt);
    Serial.print("ld=");      Serial.print(ld);
    Serial.print("\trd=");    Serial.println(rd);
    Serial.print("azimut=");  Serial.print(st->servoVal.azimut);
    Serial.print("\tpolar="); Serial.println(st->servoVal.polar);
    Serial.println();
  }
}
