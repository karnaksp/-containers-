CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++17  
LDFLAGS = -lgtest -pthread
GCFLAGS = -fprofile-arcs -ftest-coverage
VG_FLAGS =	--vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose
TEST = test

.PHONY: test

all: cat clean test

cat: 
	@chmod +x catgen.sh

test: clean
	@./catgen.sh UNIT_TEST 4
	@$(CC) $(CFLAGS) unit_tests/iterator_test.cc -o $(TEST) $(LDFLAGS) $(GCFLAGS)
	@(./$(TEST) && ./catgen.sh UNIT_TEST_PASSED 60) || ./catgen.sh UNIT_TEST_FAILED 60


clean:
	@rm -rf report
	@rm -rf lcov_files
	@rm -f *.o *.a *.out
	@rm -f *.gcda *.gcno *.info
	@rm -rf *.dSYM
	@rm -f .DS_Store */.DS_Store
	@rm -rf $(TEST)

style-check:
	@output=$$(clang-format -n -style=Google *.h  */*.h */*.tcc 2>&1); \
	if [ -n "$$output" ]; then \
		echo "$$output"; \
		./catgen.sh STYLE_TEST_FAILED 56; \
	else \
		./catgen.sh STYLE_TEST_PASSED 56; \
	fi
