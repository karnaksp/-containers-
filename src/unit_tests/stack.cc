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


TEST(s21_stack_tests_pop, s21_stack_tests_pop_01) {
    Stack<int> my_stack = Stack<int> {0,1,2,3,4,5};
    ASSERT_EQ(my_stack.empty(), false);
    ASSERT_EQ(my_stack.size(), 6);
    ASSERT_EQ(my_stack.top(), 5);
    my_stack.push(10);
    ASSERT_EQ(my_stack.top(), 10);
    my_stack.push(50);
    ASSERT_EQ(my_stack.top(), 50);
    my_stack.pop();
    ASSERT_EQ(my_stack.top(), 10);
}

TEST(s21_stack_tests_pop, s21_stack_tests_pop_02) {
    Stack<std::string> my_stack = Stack<std::string> {"One", "Two", "Three"};
    ASSERT_EQ(my_stack.empty(), false);
    ASSERT_EQ(my_stack.size(), 3);
    ASSERT_EQ(my_stack.top(), "Three");
    my_stack.push("Four");
    ASSERT_EQ(my_stack.top(), "Four");
    my_stack.push("Ten");
    ASSERT_EQ(my_stack.top(), "Ten");
    my_stack.pop();
    ASSERT_EQ(my_stack.top(), "Four");
}

TEST(s21_stack_tests_pop, s21_stack_tests_pop_03) {
Stack<std::string> my_stack = Stack<std::string> {"One", "Two", "Three"};
Stack<std::string> my_stack1 = Stack<std::string> {"Ten"};
my_stack.swap(my_stack1);
ASSERT_EQ(my_stack.top(), "Ten");
ASSERT_EQ(my_stack1.top(), "Three");
ASSERT_EQ(my_stack1.size(), 3);
ASSERT_EQ(my_stack.size(), 1);
}



}  // namespace s21