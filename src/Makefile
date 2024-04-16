CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++17  
LDFLAGS = -lgtest -pthread
GCFLAGS = -fprofile-arcs -ftest-coverage
VG_FLAGS =	--vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose
TEST = test

.PHONY: test

all: cat clean test style-check

cat: 
	@chmod +x cat.sh

test: clean
	@bash ./cat.sh UNIT_TEST 4
	@$(CC) $(CFLAGS) unit_tests/iterator_test.cc -o $(TEST) $(LDFLAGS) $(GCFLAGS)
	@./$(TEST)

clean:
	@rm -rf report
	@rm -rf lcov_files
	@rm -f *.o *.a *.out
	@rm -f *.gcda *.gcno *.info
	@rm -rf *.dSYM
	@rm -f .DS_Store */.DS_Store
	@rm -rf $(TEST)

style-check:
	@bash ./cat.sh STYLE_TEST 10
	@clang-format -n -style=Google *.h  */*.h */*.tcc
	@if [ $$? -eq 0 ]; then echo "\033[0;32m[  PASSED  ]\033[0m"; else echo "\033[0;31m[  FAILED  ]\033[0m"; fi
