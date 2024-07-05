# Adafruit INA219 MOCK Library

[![PlatformIO CI][build-shield]][build-url]
![License][license-url]
[![Contributors][contributors-shield]][contributors-url]
[![Release Version][realease-shield]][release-url]
[![PlatformIO Registry][PlatformIO-shield]][PlatformIO-url]
[![Release Date][releasedate-shield]][releasedate-url]
[![Last commit][lastcommit-shield]][lastcommit-url]

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
    mockINA.begin();
    setFakeCurrent(1234);
    int16_t result = mockINA.getCurrent_mA();
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

 <!-- MARKDOWN LINKS & IMAGES -->
[PlatformIO-shield]: https://badges.registry.platformio.org/packages/jojos1220/library/adafruit_ina219_mock.svg
[PlatformIO-url]: https://registry.platformio.org/libraries/jojos1220/adafruit_ina219_mock
[build-shield]: https://github.com/JoJos1220/adafruit_INA219_mock/actions/workflows/workflow.yml/badge.svg
[build-url]: https://github.com/JoJos1220/adafruit_INA219_mock/actions/workflows/workflow.yml
[license-url]:https://img.shields.io/github/license/Jojos1220/adafruit_INA219_mock?style=flat-square
[contributors-shield]: https://img.shields.io/github/contributors/JoJos1220/adafruit_INA219_mock
[contributors-url]: https://github.com/JoJos1220/adafruit_INA219_mock/graphs/contributors
[realease-shield]: https://img.shields.io/github/release/JoJos1220/adafruit_INA219_mock.svg?style=plastic
[release-url]: https://github.com/JoJos1220/adafruit_INA219_mock/releases/latest
[releasedate-shield]: https://img.shields.io/github/release-date/JoJos1220/adafruit_INA219_mock.svg?style=plastic
[releasedate-url]: https://github.com/JoJos1220/adafruit_INA219_mock/releases/latest/
[lastcommit-shield]: https://img.shields.io/github/last-commit/JoJos1220/adafruit_INA219_mock?style=plastic
[lastcommit-url]: https://github.com/JoJos1220/adafruit_INA219_mock/tree
