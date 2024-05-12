CC= g++
CFLAGS= -Wall -Werror -Wextra -std=c++17
DEBUG_OPTIONS= -fdiagnostics-color=always -g
HEADER_FILES= ../list/s21_list.h s21_stack.h
MAIN_FILE= main.cc
BINARY=main



stack: clean
	@ $(CC) $(CFLAGS) $(DEBUG_OPTIONS) $(HEADER_FILES) $(MAIN_FILE) -o $(BINARY)
	@./main


clean:
	@rm -rf a.out *.gch main

valgrind:
	valgrind ./$(BINARY)
	