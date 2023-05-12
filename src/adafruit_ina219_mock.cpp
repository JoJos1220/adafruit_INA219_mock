#include <adafruit_ina219_mock.h>

/*-----------------------------------------------------------------------------
 * Declaration/Definition of static Libary internal Variables
 * ----------------------------------------------------------------------------
*/
static int16_t fake_int16_BusVoltage = 0; // Define a static variable to store the fake value
static int16_t fake_int16_Current = 0;
static int16_t fake_int16_ShuntVoltage = 0;
static int16_t fake_int16_Power = 0;
static bool fake_bool_begin = false;
static bool return_bool_begin = false;

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::begin Method
 * ----------------------------------------------------------------------------
*/
bool Adafruit_INA219::begin(uint8_t addr) {
  return_bool_begin = fake_bool_begin;    // Set Global Return Value for TestUnit
  return fake_bool_begin;
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::SetCalibration Method
 * ----------------------------------------------------------------------------
*/
void Adafruit_INA219::setCalibration_32V_2A(void) {
  // Return Nothing
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::getBusVoltage Method
 * ----------------------------------------------------------------------------
*/
int16_t Adafruit_INA219::getBusVoltage_raw(void) {
  return fake_int16_BusVoltage;
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::getShuntVoltage Method
 * ----------------------------------------------------------------------------
*/
int16_t Adafruit_INA219::getShuntVoltage_raw(void) {
  return fake_int16_ShuntVoltage;
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::getCurrent Method
 * ----------------------------------------------------------------------------
*/
int16_t Adafruit_INA219::getCurrent_raw(void) {
  return fake_int16_Current;
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::getPower Method
 * ----------------------------------------------------------------------------
*/
int16_t Adafruit_INA219::getPower_raw(void) {
  return fake_int16_Power;
}

/*-----------------------------------------------------------------------------
 * setFakeBusVoltage Method to Adafruit_INA219 class
 * ----------------------------------------------------------------------------
*/
void setFakeBusVoltage(int16_t value){
  fake_int16_BusVoltage = value;
}

/*-----------------------------------------------------------------------------
 * setFakeShuntVoltage Method to Adafruit_INA219 class
 * ----------------------------------------------------------------------------
*/
void setFakeShuntVoltage(int16_t value){
  fake_int16_ShuntVoltage = value;
}

/*-----------------------------------------------------------------------------
 * setFakeCurrent Method to Adafruit_INA219 class
 * ----------------------------------------------------------------------------
*/
void setFakeCurrent(int16_t value){
 fake_int16_Current = value;
}

/*-----------------------------------------------------------------------------
 * setFakePower Method to Adafruit_INA219 class
 * ----------------------------------------------------------------------------
*/
void setFakePower(int16_t value){
  fake_int16_Power = value;
}

/*-----------------------------------------------------------------------------
 * setFakeBegin Method to Adafruit_INA219 class
 * ----------------------------------------------------------------------------
*/
void setFakeBegin(bool value){
  fake_bool_begin = value;
}

/*-----------------------------------------------------------------------------
 * getINA219 Method to Adafruit_INA219 class
 * ----------------------------------------------------------------------------
*/
bool getINA219Begin(void){
  return return_bool_begin;
}