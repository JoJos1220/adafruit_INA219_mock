# Adafruit INA219 MOCK Library

This is a simple MOCK-library for the Adafruit INA219 current sensor boards,
created for simple unity testing:
 
Check out the links above for our tutorials and wiring diagrams. This chip uses I2C to communicate.

To install, use the Arduino Library Manager and search for 'Adafruit INA219 MOCK' and install the library.

Written by JoJo1220.
MIT license, all text above must be included in any redistribution

For usage, define a Build Flag in Native Environment for Unity Testing:

```cpp
build_flags = -D NATIVE_ENVIRONMENT
```

Add the following lines in your Original Code Section enables build in Native environment.
```cpp
#ifdef NATIVE_ENVIRONMENT
    #include <adafruit_ina219_mock.h>
#else
    #include <Adafruit_INA219.h>
#endif
```

Now, testing of the original Source code within the unity Environment can be done,
without changing the original source code:
 ```cpp
#include <unity.h>

#include <adafruit_ina219_mock.h>

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_begin(void){
    Adafruit_INA219 mockINA;
    setFakeBegin(true);
    bool begin = mockINA.begin();
    TEST_ASSERT_TRUE(begin);
}
void test_getCurrent_raw(void) {
    Adafruit_INA219 mockINA;
    setFakeCurrent(1234);
    int16_t result = mockINA.getCurrent_raw();
    TEST_ASSERT_EQUAL_INT16(1234, result);
}

int main( int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_begin);
    RUN_TEST(test_getCurrent_raw);
    UNITY_END();

    return 0;
}
 ```