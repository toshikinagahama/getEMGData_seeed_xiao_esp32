#include <Arduino.h>
#include "EmgSensor.h"

void EmgSensor::initialize()
{
  pinMode(this->PIN_READ, INPUT);
}

void EmgSensor::getValues()
{
  this->raw_emg += analogRead(this->PIN_READ);
}