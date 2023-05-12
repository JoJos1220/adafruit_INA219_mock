/*!
 * @file adafruit_ina219_mock.h
 *
 * This is a simple mock-library within the <Unity> Test Environment for
 * the Adafruit INA219 Module. It simply mocks the original Libary
 * ----> https://github.com/adafruit/Adafruit_INA219.git
 *
 * Written by Johannes Reichhold.
 *
 * BSD license, all text here must be included in any redistribution.
 *
 * Tested for adafruit/Adafruit_INA219@1.2.1
 */

#ifndef ADAFRUIT_INA219_MOCK_H
#define ADAFRUIT_INA219_MOCK_H

/*-----------------------------------------------------------------------------
 * Including of Libary Dependencies
 * ----------------------------------------------------------------------------
*/
#include <stdint.h>

/*-----------------------------------------------------------------------------
 * Adafruit_INA219 MOCK Class definition
 * ----------------------------------------------------------------------------
*/
class Adafruit_INA219 {
public:
  bool begin(uint8_t addr = 0x40);
  void setCalibration_32V_2A(void);
  int16_t getBusVoltage_raw(void);
  int16_t getShuntVoltage_raw(void);
  int16_t getCurrent_raw(void);
  int16_t getPower_raw(void);
private:
  uint8_t i2caddr;
};


/*-----------------------------------------------------------------------------
 * MOCK Function definition
 * ----------------------------------------------------------------------------
*/
void setFakeBegin(bool value);
void setFakeBusVoltage(int16_t value);
void setFakeShuntVoltage(int16_t value);
void setFakeCurrent(int16_t value);
void setFakePower(int16_t value);

bool getINA219Begin(void);

#endif // ADAFRUIT_INA219_MOCK_H

