CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++17  
LDFLAGS = -lgtest -pthread
GCFLAGS = -fprofile-arcs -ftest-coverage
VG_FLAGS =	--vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose


.PHONY: test

all: cat clean test style-check

cat: 
	@chmod +x cat.sh

test: clean
	@./cat.sh "UNIT_TEST" 4

clean:
	@rm -rf report
	@rm -rf lcov_files
	@rm -f *.o *.a *.out
	@rm -f ../build/test
	@rm -f *.gcda *.gcno *.info
	@rm -rf *.dSYM
	@rm -f .DS_Store */.DS_Store

style-check:
	@./cat.sh "STYLE_TEST" 10
	@clang-format -n -style=Google *.h  */*.h */*.tcc 
