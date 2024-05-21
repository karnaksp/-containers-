# ------------------------------- VARIABLES ------------------------------------------ #
SHELL = /bin/bash
CC = g++
OPTION_FLAGS = -Wall -Werror -Wextra -g
CPP_FLAGS = -std=c++17 -lstdc++
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
GTEST_FLAGS = -lgtest -lgtest_main

OS := $(shell uname -s)
ifeq ($(OS), Linux)
    TEST_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
    TEST_FLAGS = -lcheck
endif

DIR_TEST = ./unit_tests
DIR_SRC = ./src
SRC_FILES = $(wildcard $(DIR_SRC)/*.cc)
OBJ_FILES = $(SRC_FILES:.cc=.o)
TEST_FILES = $(wildcard $(DIR_TEST)/*.cc)
TEST_OBJ = $(TEST_FILES:.cc=.o)
LIBRARY_NAME = s21_containers.a
COV_DIR = report

# ------------------------------- TASKS ------------------------------------------ #
all: clean cat build test style-check gcov_report valgrind

%.o: %.cc
	@$(CC) $(OPTION_FLAGS) $(CPP_FLAGS) $(GCOV_FLAGS) -c $< -o $@

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
	@rm -f *.o *.a *.out */*.gcda */*.gcno *.info *.txt

style-check:
	@./cat.sh "STYLE_TEST" 10
	@clang-format -n -style=Google *.h */*.h */*.tcc */*.cc
	@if [ $$? -eq 0 ]; then echo -e "\033[0;32m[  PASSED  ]\033[0m"; else echo -e "\033[0;31m[  FAILED  ]\033[0m"; fi

style-i:
	@./cat.sh "STYLE_MAKE" 10
	@clang-format -i -style=Google *.h */*.h */*.tcc */*.cc
	@if [ $$? -eq 0 ]; then echo -e "\033[0;32m[  STYLE IS C-LANG FORMATTED  ]\033[0m"; else echo -e "\033[0;31m[  FAILED  ]\033[0m"; fi

gcov_report: test
	@./cat.sh "GCOV_REPORT" 20
	@echo "Overall coverage rate:"
	@lcov --gcov-tool gcov --capture --directory . --output-file Coverage_Report.info --no-external --ignore-errors gcov > coverage_output.txt 2>&1
	@genhtml -o $(COV_DIR) Coverage_Report.info >> coverage_output.txt 2>&1
	@mkdir -p $(COV_DIR)
	@grep -E 'lines......:|functions..:' coverage_output.txt > coverage_summary.txt
	@cat coverage_summary.txt
	@lines_coverage=$$(grep 'lines......:' coverage_summary.txt | grep -o '[0-9]\+\.[0-9]\+'); \
	functions_coverage=$$(grep 'functions..:' coverage_summary.txt | grep -o '[0-9]\+\.[0-9]\+'); \
	if awk "BEGIN {exit !($$lines_coverage > 85.0 && $$functions_coverage > 85.0)}"; then \
		echo -e "\033[0;32m[  PASSED  ]\033[0m"; \
	else \
		echo -e "\033[0;31m[  FAILED  ]\033[0m"; \
	fi

valgrind: build
	@./cat.sh "VALGRIND_TEST" 32
	@valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test 2>&1 | grep -E "ERROR SUMMARY:" > valgrind_summary.txt; \
	if [ $$? -eq 0 ]; then echo -e "\033[0;32m[  PASSED  ]\033[0m"; else echo -r "\033[0;31m[  FAILED  ]\033[0m"; cat valgrind_summary.txt; fi;

open_report:
	@open ./report/index.html || xdg-open ./report/index.html || start ./report/index.html

documentation:
	@doxygen ./Doxyfile
	@open ./docs/html/index.html

.PHONY: clean test build style-check
