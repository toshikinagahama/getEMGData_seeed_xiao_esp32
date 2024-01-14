#include "BatterySensor.h"

void BatterySensor::initialize()
{
  pinMode(this->PIN_WAKEUP, OUTPUT);
  pinMode(this->PIN_READ, INPUT);
}

void BatterySensor::getValues()
{
  digitalWrite(this->PIN_WAKEUP, HIGH); // トランジスタON
  delay(100);
  this->raw_vol = 0;
  for (uint8_t i = 0; i < 16; i++)
  {
    this->raw_vol += analogRead(this->PIN_READ);
  }
  this->raw_vol /= 16;
  float vol = (float)this->raw_vol * 2 * (1.85 / 4095);
  this->level = int((vol - 1.441138) / (2.24415 - 1.441138) * 100);
  Serial.printf("%d\n", this->raw_vol);
  digitalWrite(this->PIN_WAKEUP, LOW); // トランジスタOFF
}