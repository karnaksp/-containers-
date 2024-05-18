CC= g++
CFLAGS= -Wall -Werror -Wextra -std=c++17
DEBUG_OPTIONS= -fdiagnostics-color=always -g
HEADER_FILES= ../vector/s21_vector.h
MAIN_FILE= main.cc
BINARY=main



vector: clean
	@ $(CC) $(CFLAGS) $(DEBUG_OPTIONS) $(HEADER_FILES) $(MAIN_FILE) -o $(BINARY)
	@./main


clean:
	@rm -rf a.out *.gch main

valgrind:
	valgrind ./$(BINARY)