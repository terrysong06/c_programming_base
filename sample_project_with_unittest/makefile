# makefile - 빌드 자동화 설정
#
# 사용법:
#   make        - 프로그램 빌드
#   make test   - 모든 테스트 실행
#   make clean  - 빌드 산출물 삭제

CC = gcc
CFLAGS = -Wall -Wextra -g

# 최종 실행 파일 (Code Runner가 읽음)
TARGET = calculator.out

# 프로그램 소스
PROG_SRCS = main.c calc.c display.c
PROG_OBJS = $(PROG_SRCS:.c=.o)

# 테스트 소스
TEST_CALC_SRCS = test_calc.c calc.c
TEST_CALC_OBJS = $(TEST_CALC_SRCS:.c=.o)
TEST_CALC_TARGET = test_calc.out

# 기본 타겟: 프로그램 빌드
all: $(TARGET)

# 프로그램 빌드
$(TARGET): $(PROG_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 모든 테스트 실행
test: test_calc
	@echo "\n✅ 모든 테스트 완료!\n"

# calc 테스트 빌드 및 실행
test_calc: $(TEST_CALC_TARGET)
	@echo "\n🚀 calc 함수 테스트 실행 중...\n"
	./$(TEST_CALC_TARGET)

# 테스트 실행파일 빌드
$(TEST_CALC_TARGET): $(TEST_CALC_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 컴파일: 각 .c 파일을 .o로 컴파일
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 정리
clean:
	rm -f *.o *.out

.PHONY: all test test_calc clean

