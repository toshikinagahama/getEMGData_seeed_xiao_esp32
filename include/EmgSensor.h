#ifndef EMGSENSOR_H
#define EMGSENSOR_H
#include <Arduino.h>
// 姿勢クラス
class EmgSensor
{

private:
  const uint8_t PIN_READ = D1;

public:
  uint16_t raw_emg;

  /**
   *
   * 初期化
   *
   */
  void initialize();
  void getValues();
};

#endif // EMGSENSOR_H