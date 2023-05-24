#include <adafruit_ina219_mock.h>

/*-----------------------------------------------------------------------------
 * Declaration/Definition of static Libary internal Variables
 * ----------------------------------------------------------------------------
*/
// Definition of static variables to store fake values
static int16_t fake_int16_BusVoltage = 0; 
static int16_t fake_int16_Current = 0;
static int16_t fake_int16_ShuntVoltage = 0;
static int16_t fake_int16_Power = 0;
static bool fake_bool_success = false;
static bool fake_bool_begin = false;
static bool return_bool_begin = false;
static bool return_bool_powerSave = false;

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::Konstructor
 * ----------------------------------------------------------------------------
*/
Adafruit_INA219::Adafruit_INA219(uint8_t addr){
  ina219_currentDivider_mA = 0;
  ina219_powerMultiplier_mW = 0.0f;
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::Destructor
 * ----------------------------------------------------------------------------
*/
Adafruit_INA219::~Adafruit_INA219(){}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::begin Method
 * ----------------------------------------------------------------------------
*/
bool Adafruit_INA219::begin(uint8_t addr) {
  return_bool_begin = fake_bool_begin;    // Set Global Return Value for TestUnit
  setCalibration_32V_2A();
  return fake_bool_begin;
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::SetCalibration Method 32V/2A
 * ----------------------------------------------------------------------------
*/
void Adafruit_INA219::setCalibration_32V_2A(void) {
  ina219_currentDivider_mA = 10; // Current LSB = 100uA per bit (1000/100 = 10)
  ina219_powerMultiplier_mW = 2; // Power LSB = 1mW per bit (2/1)
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::SetCalibration Method 32V/1A
 * ----------------------------------------------------------------------------
*/
void Adafruit_INA219::setCalibration_32V_1A(void) {
  ina219_currentDivider_mA = 25;    // Current LSB = 40uA per bit (1000/40 = 25)
  ina219_powerMultiplier_mW = 0.8f; // Power LSB = 800uW per bit 
};

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::SetCalibration Method 16V/400mA
 * ----------------------------------------------------------------------------
*/
void Adafruit_INA219::setCalibration_16V_400mA(void) {
  ina219_currentDivider_mA = 20;    // Current LSB = 50uA per bit (1000/50 = 20)
  ina219_powerMultiplier_mW = 1.0f; // Power LSB = 1mW per bit
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::getBusVoltage_raw Method
 * ----------------------------------------------------------------------------
*/
int16_t Adafruit_INA219::getBusVoltage_raw(void) {
  return fake_int16_BusVoltage;
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::getShuntVoltage_raw Method
 * ----------------------------------------------------------------------------
*/
int16_t Adafruit_INA219::getShuntVoltage_raw(void) {
  return fake_int16_ShuntVoltage;
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::getCurrent_raw Method
 * ----------------------------------------------------------------------------
*/
int16_t Adafruit_INA219::getCurrent_raw(void) {
  return fake_int16_Current;
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::getPower_raw Method
 * ----------------------------------------------------------------------------
*/
int16_t Adafruit_INA219::getPower_raw(void) {
  return fake_int16_Power;
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::getShuntVoltage_mV Method
 * ----------------------------------------------------------------------------
*/
float Adafruit_INA219::getShuntVoltage_mV(void){
  return Adafruit_INA219::getShuntVoltage_raw();
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::getBusVoltage_V Method
 * ----------------------------------------------------------------------------
*/
float Adafruit_INA219::getBusVoltage_V(void){
  return Adafruit_INA219::getBusVoltage_raw();
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::getCurrent_mA Method
 * ----------------------------------------------------------------------------
*/
float Adafruit_INA219::getCurrent_mA(void) {
  return (float)Adafruit_INA219::getCurrent_raw();  
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::getPower_mW Method
 * ----------------------------------------------------------------------------
*/
float Adafruit_INA219::getPower_mW(void) {
  return (float)Adafruit_INA219::getPower_raw();
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::powerSave Method
 * ----------------------------------------------------------------------------
*/
void Adafruit_INA219::powerSave(bool on){
  return_bool_powerSave = on;
}

/*-----------------------------------------------------------------------------
 * Adafruit_INA219::success Method
 * ----------------------------------------------------------------------------
*/
bool Adafruit_INA219::success(void){
  return fake_bool_success;
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
 * setFakeSuccess Method to Adafruit_INA219 class
 * ----------------------------------------------------------------------------
*/
void setFakeSuccess(bool value){
  fake_bool_success = value;
}

/*-----------------------------------------------------------------------------
 * getINA219Begin Method to Adafruit_INA219 class
 * ----------------------------------------------------------------------------
*/
bool getINA219Begin(void){
  return return_bool_begin;
}

/*-----------------------------------------------------------------------------
 * getPowerSave Method to Adafruit_INA219 class
 * ----------------------------------------------------------------------------
*/
bool getPowerSave(void){
  return return_bool_powerSave;
}