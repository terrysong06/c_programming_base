/**
 * test_calc.c - calc.c 함수들의 unittest
 */
#include "calc.h"
#include "test_runner.h"

int main() {
  TEST_START("add 함수 테스트");

  ASSERT_EQ(5, add(2, 3));
  ASSERT_EQ(0, add(0, 0));
  ASSERT_EQ(-1, add(-5, 4));
  ASSERT_EQ(100, add(50, 50));

  TEST_START("subtract 함수 테스트");

  ASSERT_EQ(1, subtract(3, 2));
  ASSERT_EQ(0, subtract(5, 5));
  ASSERT_EQ(-9, subtract(-5, 4));
  ASSERT_EQ(10, subtract(20, 10));

  TEST_START("multiply 함수 테스트");

  ASSERT_EQ(6, multiply(2, 3));
  ASSERT_EQ(0, multiply(0, 100));
  ASSERT_EQ(-12, multiply(-3, 4));
  ASSERT_EQ(25, multiply(5, 5));

  TEST_SUMMARY();
}

