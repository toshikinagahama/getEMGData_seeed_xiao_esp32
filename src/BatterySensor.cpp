#include "BatterySensor.h"

void BatterySensor::initialize()
{
  pinMode(this->PIN_WAKEUP, OUTPUT);
  pinMode(this->PIN_READ, INPUT);
}

void BatterySensor::getValues()
{
  // digitalWrite(this->PIN_WAKEUP, LOW); // トランジスタON
  digitalWrite(this->PIN_WAKEUP, HIGH); // トランジスタON
  delay(100);
  this->raw_vol = analogRead(this->PIN_READ);
  float vol = (float)this->raw_vol * 2.92 / 4095;
  this->level = int((vol - 1.441138) / (2.1 - 1.441138) * 100);
  Serial.printf("%f\n", vol);
  // Serial.printf("%f\n", this->raw_vol);
  // digitalWrite(this->PIN_WAKEUP, HIGH); // トランジスタOFF
  digitalWrite(this->PIN_WAKEUP, LOW); // トランジスタOFF
}