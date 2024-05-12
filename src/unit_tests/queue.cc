#include "tests.h"

namespace s21 {

TEST(s21_Queue_tests_construct, s21_Queue_tests_construct_01) {
  Queue<int> my_Queue;
  ASSERT_EQ(my_Queue.empty(), true);
  ASSERT_EQ(my_Queue.size(), 0);
}

TEST(s21_Queue_tests_construct, s21_Queue_tests_construct_02) {
  Queue<int> my_Queue{0, 1, 2, 3};
  ASSERT_EQ(my_Queue.empty(), false);
  ASSERT_EQ(my_Queue.size(), 4);
  ASSERT_EQ(my_Queue.back(), 3);
  ASSERT_EQ(my_Queue.front(), 0);
}

TEST(s21_Queue_tests_construct, s21_Queue_tests_construct_03) {
  Queue<int> my_Queue = Queue<int>{0, 1, 2, 3, 4, 5};
  ASSERT_EQ(my_Queue.empty(), false);
  ASSERT_EQ(my_Queue.size(), 6);
  ASSERT_EQ(my_Queue.back(), 5);
  ASSERT_EQ(my_Queue.front(), 0);
}

TEST(s21_Queue_tests_pop, s21_Queue_tests_pop_01) {
  Queue<int> my_Queue = Queue<int>{0, 1, 2, 3, 4, 5};
  ASSERT_EQ(my_Queue.empty(), false);
  ASSERT_EQ(my_Queue.size(), 6);
  ASSERT_EQ(my_Queue.back(), 5);
  my_Queue.push(10);
  ASSERT_EQ(my_Queue.back(), 10);
  my_Queue.push(50);
  ASSERT_EQ(my_Queue.back(), 50);
  my_Queue.pop();
  ASSERT_EQ(my_Queue.front(), 1);
}

TEST(s21_Queue_tests_pop, s21_Queue_tests_pop_02) {
  Queue<std::string> my_Queue = Queue<std::string>{"One", "Two", "Three"};
  ASSERT_EQ(my_Queue.empty(), false);
  ASSERT_EQ(my_Queue.size(), 3);
  ASSERT_EQ(my_Queue.back(), "Three");
  my_Queue.push("Four");
  ASSERT_EQ(my_Queue.back(), "Four");
  my_Queue.push("Ten");
  ASSERT_EQ(my_Queue.back(), "Ten");
  my_Queue.pop();
  ASSERT_EQ(my_Queue.front(), "Two");
  ASSERT_EQ(my_Queue.back(), "Ten");
}

TEST(s21_Queue_tests_pop, s21_Queue_tests_pop_03) {
  Queue<std::string> my_Queue = Queue<std::string>{"One", "Two", "Three"};
  Queue<std::string> my_Queue1 = Queue<std::string>{"Ten"};
  my_Queue.swap(my_Queue1);
  ASSERT_EQ(my_Queue.front(), "Ten");
  ASSERT_EQ(my_Queue.back(), "Ten");
  ASSERT_EQ(my_Queue1.front(), "One");
  ASSERT_EQ(my_Queue1.back(), "Three");
  ASSERT_EQ(my_Queue1.size(), 3);
  ASSERT_EQ(my_Queue.size(), 1);
}

}  // namespace s21