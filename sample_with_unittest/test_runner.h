/**
 * test_runner.h - 간단한 테스트 프레임워크
 *
 * C언어에서 사용할 수 있는 간단한 unittest 헬퍼
 */
#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include <stdio.h>
#include <stdlib.h>

// 테스트 통계
static int tests_run = 0;
static int tests_passed = 0;
static int tests_failed = 0;

// Assert 매크로
#define ASSERT_EQ(expected, actual)                                            \
  do {                                                                         \
    tests_run++;                                                               \
    if ((expected) != (actual)) {                                              \
      printf("  ❌ FAIL: %s:%d - Expected %d, got %d\n", __FILE__, __LINE__,  \
             (expected), (actual));                                            \
      tests_failed++;                                                          \
    } else {                                                                   \
      tests_passed++;                                                          \
      printf("  ✓ PASS\n");                                                    \
    }                                                                          \
  } while (0)

#define ASSERT_TRUE(condition)                                                 \
  do {                                                                         \
    tests_run++;                                                               \
    if (!(condition)) {                                                       \
      printf("  ❌ FAIL: %s:%d - Condition is false\n", __FILE__, __LINE__);  \
      tests_failed++;                                                          \
    } else {                                                                   \
      tests_passed++;                                                          \
      printf("  ✓ PASS\n");                                                    \
    }                                                                          \
  } while (0)

// 테스트 시작/종료
#define TEST_START(name)                                                       \
  printf("\n🧪 Testing: %s\n", name);

#define TEST_SUMMARY()                                                         \
  do {                                                                         \
    printf("\n"                                                                \
           "================================\n"                                \
           "  테스트 결과\n"                                                    \
           "================================\n");                              \
    printf("  총 테스트: %d\n", tests_run);                                    \
    printf("  통과: %d\n", tests_passed);                                      \
    printf("  실패: %d\n", tests_failed);                                      \
    if (tests_failed == 0) {                                                   \
      printf("\n  ✅ 모든 테스트 통과!\n\n");                                   \
      return 0;                                                                \
    } else {                                                                   \
      printf("\n  ❌ 일부 테스트 실패\n\n");                                    \
      return 1;                                                                \
    }                                                                          \
  } while (0)

#endif

