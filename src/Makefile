# ------------------------------- FLAG CREATION ------------------------------------------ #
CC=g++
OPTION_FLAGS=-Wall -Werror -Wextra -g
CPP_FLAGS=-lstdc++ -std=c++17
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
GTEST_FLAGS=-lgtest -lgtest_main
OS := $(shell uname -s)
ifeq ($(OS), Linux)
    TEST_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
    TEST_FLAGS = -lcheck
endif
DIR_TEST=./unit_tests
DIR_SRC=./src
CONTAINERS= rb-tree set map # add folders
SRC_FILES := $(wildcard $(addsuffix /*.cc,$(DIR_SRC)))
OBJ_FILES := $(patsubst %.cc,%.o,$(SRC_FILES))
TEST_FILES := $(wildcard $(addsuffix /*.cc,$(DIR_TEST)))
TEST_OBJ := $(patsubst %.cc,%.o,$(TEST_FILES))
LIBRARY_NAME = s21_containers.a
COV_DIR=coverage # Directory for coverage files

# ------------------------------- TASKS ------------------------------------------ #
all: clean cat build test style-check gcov_report valgrind

%.o: %.cc
	$(CC) $(OPTION_FLAGS) $(CPP_FLAGS) $(GCOV_FLAGS) -c $< -o $@

$(LIBRARY_NAME): $(OBJ_FILES)
	@ar rcs $(LIBRARY_NAME) $(OBJ_FILES)

build: $(LIBRARY_NAME)

test: $(LIBRARY_NAME) $(TEST_OBJ)
	@./cat.sh "UNIT_TEST" 4
	@$(CC) $(OPTION_FLAGS) $(CPP_FLAGS) $(GCOV_FLAGS) $^ -o test $(GTEST_FLAGS) $(TEST_FLAGS)
	@./test

cat:
	@chmod +x cat.sh

clean:
	@rm -rf report $(COV_DIR) ./test $(LIBRARY_NAME) $(TEST_OBJ)
	@rm -f *.o *.a *.out */*.gcda */*.gcno *.info valgrind_summary.txt

style-check:
	@./cat.sh "STYLE_TEST" 10
	@clang-format -n -style=Google *.h */*.h */*.tcc */*.cc
	@if [ $$? -eq 0 ]; then echo "\033[0;32m          [  PASSED  ]\033[0m"; else echo "\033[0;31m          [  FAILED  ]\033[0m"; fi

style-i:
	@./cat.sh "STYLE_MAKE" 10
	@clang-format -i -style=Google *.h */*.h */*.tcc */*.cc
	@if [ $$? -eq 0 ]; then echo "\033[0;32m          [  STYLE IS C-LANG FORMATTED  ]\033[0m"; else echo "\033[0;31m          [  FAILED  ]\033[0m"; fi

gcov_report: test
	@./cat.sh "GCOV_REPORT" 20
	@lcov --gcov-tool gcov --capture --directory . --output-file Coverage_Report.info --no-external --ignore-errors gcov
	@genhtml -o report Coverage_Report.info
	@mkdir -p $(COV_DIR)
	@echo "\033[0;32m                    [  PASSED  ]\033[0m";

valgrind: build
	@./cat.sh "VALGRIND_TEST" 32
	@valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test 2>&1 | grep -E "ERROR SUMMARY:" > valgrind_summary.txt; \
	if [ $$? -eq 0 ]; then echo "\033[0;32m                                [  PASSED  ]\033[0m"; else echo "\033[0;31m                                [  FAILED  ]\033[0m"; cat valgrind_summary.txt; fi;

open_report:
	@open ./report/index.html || xdg-open ./report/index.html || start ./report/index.html

.PHONY: clean test build style-check

# Ensure object files are compiled with coverage flags
%.o: %.cc
	$(CC) $(OPTION_FLAGS) $(CPP_FLAGS) $(GCOV_FLAGS) -c $< -o $@
