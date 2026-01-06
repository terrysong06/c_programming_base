/**
 * test_sample.c - sample.c 함수들의 unittest
 */
#include "sample.h"
#include "test_runner.h"

int main() {
  TEST_START("get_star_count 함수 테스트");

  // 첫 번째 줄: 별 1개
  ASSERT_EQ(1, get_star_count(1, 5));

  // 두 번째 줄: 별 3개
  ASSERT_EQ(3, get_star_count(2, 5));

  // 세 번째 줄: 별 5개
  ASSERT_EQ(5, get_star_count(3, 5));

  // 네 번째 줄: 별 7개
  ASSERT_EQ(7, get_star_count(4, 5));

  // 다섯 번째 줄: 별 9개
  ASSERT_EQ(9, get_star_count(5, 5));

  // 경계값 테스트: 범위 밖
  ASSERT_EQ(0, get_star_count(0, 5));
  ASSERT_EQ(0, get_star_count(6, 5));

  // 다른 높이 테스트
  ASSERT_EQ(1, get_star_count(1, 3));
  ASSERT_EQ(3, get_star_count(2, 3));
  ASSERT_EQ(5, get_star_count(3, 3));

  TEST_SUMMARY();
}

