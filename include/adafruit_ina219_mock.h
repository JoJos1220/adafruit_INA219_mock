#ifndef ADAFRUIT_INA219_MOCK_H
#define ADAFRUIT_INA219_MOCK_H

#include <ArduinoFake.h>

class Adafruit_INA219_Mock {
public:
  void begin(void);
  void setCalibration_32V_2A(void);
  int16_t getBusVoltage_raw(void);
  int16_t getShuntVoltage_raw(void);
  int16_t getCurrent_raw(void);
  int16_t getPower_raw(void);
};

#endif // ADAFRUIT_INA219_MOCK_H
