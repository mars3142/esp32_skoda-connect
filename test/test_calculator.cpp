#ifdef ARDUINO
#include <Arduino.h>
#endif

#include <unity.h>

void test_function_calculator_addition(void)
{
    TEST_ASSERT_EQUAL(32, 20 + 12);
}

void test_function_calculator_subtraction(void)
{
    TEST_ASSERT_EQUAL(20, 24 - 4);
}

void test_function_calculator_multiplication(void)
{
    TEST_ASSERT_EQUAL(50, 5 * 10);
}

void test_function_calculator_division(void)
{
    TEST_ASSERT_EQUAL(32, 64 / 2);
}

#ifdef ARDUINO
void setup()
{
    delay(2000); // add 2-sec wait for the board w/o software resetting via
                 // Serial.DTR/RTS
#else
int main(int argc, char *argv[])
{
#endif
    UNITY_BEGIN();
    RUN_TEST(test_function_calculator_addition);
    RUN_TEST(test_function_calculator_subtraction);
    RUN_TEST(test_function_calculator_multiplication);
    RUN_TEST(test_function_calculator_division);
    UNITY_END();

#ifndef ARDUINO
    return 0;
#endif
}

#ifdef ARDUINO
void loop()
{
}
#endif
