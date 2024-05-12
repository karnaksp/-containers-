#include <iostream>
#include <stack>

#include "s21_stack.h"

int main() {
  std::cout << "Test" << std::endl;

  s21::Stack<int> my_stack = s21::Stack<int>{1, 2, 3, 4, 5, 10, -10};
  s21::Stack<int> my_stack1 = s21::Stack<int>{
      3,
      4,
      5,
  };

  std::cout << "top: " << my_stack.top() << std::endl;
  std::cout << "empty: " << std::boolalpha << my_stack.empty() << std::endl;
  std::cout << "size: " << my_stack.size() << std::endl;

  my_stack.push(44);
  std::cout << "top: " << my_stack.top() << std::endl;
  my_stack.pop();
  std::cout << "top: " << my_stack.top() << std::endl;

  my_stack.swap(my_stack1);

  my_stack.print_all();

  return 0;
}