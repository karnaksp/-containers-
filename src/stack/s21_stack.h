#ifndef S21_STACK_H
#define S21_STACK_H

#include <cstddef>
#include <initializer_list>
#include <limits>

#include "../list/s21_ListNode.h"
#include "../list/s21_iterator.h"
#include "../list/s21_list.h"

namespace s21 {

using size_type = std::size_t;

template <typename T>
class Stack {
 private:
  List<T> stack_;

 public:
  /**********************************
   *
   *   Stack Helper Functions
   *
   ***********************************/
  void print_all();

  /**********************************
   *
   *   Stack Member functions
   *
   ***********************************/

  // default constructor, creates an empty queue
  Stack();

  // initializer list constructor, creates queue
  // initizialized using std::initializer_list
  Stack(std::initializer_list<T> const &items);

  // copy constructor
  Stack(const Stack<T> &s);

  // move constructor
  Stack(Stack &&s);

  // destructor
  ~Stack();

  // assignment operator overload for moving an object
  Stack<T> operator=(Stack &&s);

  /**********************************
   *
   *   Stack Element access
   *
   ***********************************/

  // accesses the top element
  const T &top();

  /**********************************
   *
   *   Stack Capacity
   *
   ***********************************/

  // checks whether the container is empty
  bool empty();

  // returns the number of elements
  size_type size();

  /**********************************
   *
   *   Stack Modifiers
   *
   ***********************************/

  // inserts an element at the end
  void push(const T &value);

  // removes the first element
  void pop();

  // swaps the contents
  void swap(Stack &other);
};

/**********************************
 *
 *   Stack Helper Functions
 *
 ***********************************/
template <typename T>
void Stack<T>::print_all() {
  stack_.print_all_valid_nodes();
}

/**********************************
 *
 *   Stack Member functions
 *
 ***********************************/

// default constructor, creates an empty queue
template <typename T>
Stack<T>::Stack() {}

// initializer list constructor, creates queue
// initizialized using std::initializer_list
template <typename T>
Stack<T>::Stack(std::initializer_list<T> const &items) {
  for (auto it = items.begin(); it != items.end(); it++) {
    this->stack_.push_back(*it);
  }
}

// copy constructor
template <typename T>
Stack<T>::Stack(const Stack<T> &s) {
  this->stack_ = s.stack_;
}

// move constructor
template <typename T>
Stack<T>::Stack(Stack &&s) {
  this->stack_ = s.stack_;
}

// destructor
template <typename T>
Stack<T>::~Stack() {}

// assignment operator overload for moving an object
template <typename T>
Stack<T> Stack<T>::operator=(Stack &&s) {
  this->stack_ = s.stack_;
  return *this;
}

/**********************************
 *
 *   Stack Element access
 *
 ***********************************/

// accesses the top element
template <typename T>
const T &Stack<T>::top() {
  return this->stack_.back();
}

/**********************************
 *
 *   Stack Capacity
 *
 ***********************************/

// checks whether the container is empty
template <typename T>
bool Stack<T>::empty() {
  return this->stack_.empty();
}

// returns the number of elements
template <typename T>
size_type Stack<T>::size() {
  return this->stack_.size();
}

/**********************************
 *
 *   Stack Modifiers
 *
 ***********************************/

// inserts an element at the end
template <typename T>
void Stack<T>::push(const T &value) {
  this->stack_.push_back(value);
}

// removes the first element
template <typename T>
void Stack<T>::pop() {
  this->stack_.pop_back();
}

// swaps the contents
template <typename T>
void Stack<T>::swap(Stack &other) {
  this->stack_.swap(other.stack_);
}

}  // namespace s21

#endif