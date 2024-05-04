CC= g++
CFLAGS= -Wall -Werror -Wextra -std=c++17

run:
	@ $(CC) $(CFLAGS) myTests.cpp
	@ ./a.out

iterator:
	@ $(CC) $(CFLAGS) tests_iterator.cpp
	@./a.out

list: clean
	@ $(CC) $(CFLAGS) main.cc s21_list.cc s21_list.h -o main
	@./main

initialization_list:
	@ $(CC) $(CFLAGS) tests_initialization_list.cpp
	@./a.out

clean:
	@rm -rf a.out *.gch main
	