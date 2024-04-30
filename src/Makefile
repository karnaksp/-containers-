# ------------------------------- FLAG CREATION ------------------------------------------ #
CC=g++
OPTION_FLAGS=-Wall -Werror -Wextra -g
CPP_FLAGS=-lstdc++ -std=c++17
GCOV_FLAGS=--coverage
GTEST_FLAGS=-lgtest
OS := $(shell uname -s)
ifeq ($(OS), Linux)
    TEST_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
    TEST_FLAGS = -lcheck
endif
DIR_TEST=./unit_tests
DIR_SRC=./src
CONTAINERS= set rb-tree # add folders
SRC_FILES := $(wildcard $(addsuffix /*.cc,$(DIR_SRC)))
OBJ_FILES := $(patsubst %.cc,%.o,$(SRC_FILES))
TEST_FILES := $(wildcard $(addsuffix /*.cc,$(DIR_TEST)))
TEST_OBJ := $(patsubst %.cc,%.o,$(TEST_FILES))
LIBRARY_NAME = s21_containers.a
# ------------------------------- TASKS ------------------------------------------ #
all: cat clean build test style-check gcov_report valgrind

test: $(LIBRARY_NAME) $(TEST_OBJ)
	@./cat.sh "UNIT_TEST" 4
	@$(CC) $(OPTION_FLAGS) $(CPP_FLAGS) $^ -o test $(GTEST_FLAGS) $(TEST_FLAGS)
	@./test

build: $(LIBRARY_NAME)

$(LIBRARY_NAME): $(OBJ_FILES)
	@ar rcs $(LIBRARY_NAME) $(OBJ_FILES)

cat: 
	@chmod +x cat.sh

clean:
	@rm -rf report lcov_files ./test $(LIBRARY_NAME) $(TEST_OBJ)
	@rm -f *.o *.a *.out *.gcda *.gcno *.info valgrind_summary.txt

style-check:
	@./cat.sh "STYLE_TEST" 10
	@clang-format -n -style=Google *.h  */*.h */*.tcc */*.cc
	@if [ $$? -eq 0 ]; then echo "\033[0;32m          [  PASSED  ]\033[0m"; else echo "\033[0;31m          [  FAILED  ]\033[0m"; fi

gcov_report: $(LIBRARY_NAME) $(TEST_OBJ)
	@./cat.sh "GCOV_REPORT" 20
	@echo "\033[0;32m                    [  PASSED  ]\033[0m";

valgrind: build
	@./cat.sh "VALGRIND_TEST" 32
	@valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test 2>&1 | grep -E "ERROR SUMMARY:" > valgrind_summary.txt; \
	if [ $$? -eq 0 ]; then echo "\033[0;32m                                [  PASSED  ]\033[0m"; else echo "\033[0;31m                                [  FAILED  ]\033[0m"; cat valgrind_summary.txt; fi; \

.PHONY: lean test build style-check