#include "adafruit_ina219_mock.h"

void Adafruit_INA219_Mock::begin(void) {
  // do nothing
}

void Adafruit_INA219_Mock::setCalibration_32V_2A(void) {
  // do nothing
}

int16_t Adafruit_INA219_Mock::getBusVoltage_raw(void) {
  return fakeit::DefaultValue<int16_t>::get();
}

int16_t Adafruit_INA219_Mock::getShuntVoltage_raw(void) {
  return fakeit::DefaultValue<int16_t>::get();
}

int16_t Adafruit_INA219_Mock::getCurrent_raw(void) {
  return fakeit::DefaultValue<int16_t>::get();
}

int16_t Adafruit_INA219_Mock::getPower_raw(void) {
  return fakeit::DefaultValue<int16_t>::get();
}