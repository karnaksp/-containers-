CC= g++
CFLAGS= -Wall -Werror -Wextra -std=c++17
DEBUG_OPTIONS= -fdiagnostics-color=always -g
SOURCE_FILES= s21_iterator.cc s21_list.cc s21_node.cc 
HEADER_FILES= s21_iterator.h s21_list.h s21_node.h
MAIN_FILE= main.cc
BINARY=main

run_test_with_not_my_list:
	@ $(CC) $(CFLAGS) tests_list.cpp
	@ ./a.out

run_test_with_not_my_iterator:
	@ $(CC) $(CFLAGS) tests_iterator.cpp
	@./a.out

list: clean
	@ $(CC) $(CFLAGS) $(DEBUG_OPTIONS) $(HEADER_FILES) $(MAIN_FILE) -o $(BINARY)
	@./main

run_test_with_not_my_initialization_list:
	@ $(CC) $(CFLAGS) tests_initialization_list.cpp
	@./a.out

clean:
	@rm -rf a.out *.gch main

valgrind:
	valgrind ./$(BINARY)
	