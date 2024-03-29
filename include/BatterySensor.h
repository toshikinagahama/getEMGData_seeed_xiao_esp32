#ifndef BATTERYSENSOR_H
#define BATTERYSENSOR_H
#include <Arduino.h>
class BatterySensor
{

private:
  const uint8_t PIN_WAKEUP = D3;
  const uint8_t PIN_READ = D0;

public:
  float raw_vol = 0.0;
  uint8_t level = 0;

  /**
   *
   * 初期化
   *
   */
  void initialize();
  void getValues();
};

#endif // BATTERYSENSOR_H