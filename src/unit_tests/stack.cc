#include "tests.h"

namespace s21 {

TEST(s21_stack_tests_construct, s21_stack_tests_construct_01) {
    Stack<int> my_stack;
    ASSERT_EQ(my_stack.empty(), true);
    ASSERT_EQ(my_stack.size(), 0);
}

TEST(s21_stack_tests_construct, s21_stack_tests_construct_02) {
    Stack<int> my_stack {0,1,2,3};
    ASSERT_EQ(my_stack.empty(), false);
    ASSERT_EQ(my_stack.size(), 4);
    ASSERT_EQ(my_stack.top(), 3);
}

TEST(s21_stack_tests_construct, s21_stack_tests_construct_03) {
    Stack<int> my_stack = Stack<int> {0,1,2,3,4,5};
    ASSERT_EQ(my_stack.empty(), false);
    ASSERT_EQ(my_stack.size(), 6);
    ASSERT_EQ(my_stack.top(), 5);
}


TEST(s21_stack_tests_pop, s21_stack_tests_pop_03) {
    Stack<int> my_stack = Stack<int> {0,1,2,3,4,5};
    ASSERT_EQ(my_stack.empty(), false);
    ASSERT_EQ(my_stack.size(), 6);
    ASSERT_EQ(my_stack.top(), 5);
}


}  // namespace s21