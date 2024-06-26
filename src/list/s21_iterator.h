#ifndef S21_ITERATOR
#define S21_ITERATOR

#include <cstddef>

#include "s21_ListNode.h"

namespace s21 {

using size_type = std::size_t;

template <typename T>
class ListIterator {
 public:
  // using value_type = T;
  // using reference = value_type&;
  // using const_reference = const value_type&;
  // using iterator = ListIterator;
  using size_type = std::size_t;

 public:
  ListNode<T>* current;

 public:
  // constructor with address parametr
  ListIterator(ListNode<T>* address);
  ListIterator(const ListNode<T>* address);

  // Copy constructor
  ListIterator(const ListIterator& other);

  // Move constructor
  ListIterator(ListIterator&& other);

  // Destructor
  ~ListIterator() {}

  // Copy assignment operator(=).
  ListIterator<T>& operator=(const ListIterator<T>& rhs);

  // Move assignment operator(=).
  ListIterator<T>& operator=(ListIterator<T>&& rhs);

  T& operator*();

  // prefix ++
  ListIterator<T>& operator++();

  // postfix ++
  ListIterator<T> operator++(int);

  // prefix --
  ListIterator<T>& operator--();

  // postfix --
  ListIterator<T> operator--(int);

  bool operator==(const ListIterator<T>& rhs);
  bool operator!=(const ListIterator<T>& rhs);
};

template <typename T>
ListIterator<T>::ListIterator(ListNode<T>* address) {
  this->current = address;
}

template <typename T>
ListIterator<T>::ListIterator(const ListNode<T>* address) {
  s21::ListNode<int>* tmp = address;
  this->current = tmp;
}

template <typename T>
ListIterator<T>::ListIterator(const ListIterator<T>& other) {
  this->current = other.current;
}

template <typename T>
ListIterator<T>::ListIterator(ListIterator<T>&& other) {
  this->current = other.current;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator=(const ListIterator<T>& rhs) {
  this->current = rhs.current;
  return *this;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator=(ListIterator<T>&& rhs) {
  this->current = rhs.current;
  return *this;
}

template <typename T>
T& ListIterator<T>::operator*() {
  return this->current->get_value();
}

// prefix ++
template <typename T>
ListIterator<T>& ListIterator<T>::operator++() {
  if (this->current->get_next() != nullptr) {
    this->current = this->current->get_next();
  } else {
    auto curr = this->current;
    for (; curr->get_prev()->get_prev() != nullptr; curr = curr->get_prev()) {
    }
    this->current = curr;
  }
  return *this;
}

// postfix ++
template <typename T>
ListIterator<T> ListIterator<T>::operator++(int) {
  ListIterator tmp = ListIterator(this->current);
  if (this->current->get_next() != nullptr) {
    this->current = this->current->get_next();
  } else {
    auto curr = this->current;
    for (; curr->get_prev()->get_prev() != nullptr; curr = curr->get_prev()) {
    }
    this->current = curr;
  }
  return tmp;
}

// prefix --
template <typename T>
ListIterator<T>& ListIterator<T>::operator--() {
  if (this->current->get_prev()->get_prev() != nullptr) {
    this->current = this->current->get_prev();
  } else {
    auto curr = this->current;
    for (; curr->get_next() != nullptr; curr = curr->get_next()) {
    }
    this->current = curr;
  }
  return *this;
}

// postfix --
template <typename T>
ListIterator<T> ListIterator<T>::operator--(int) {
  auto tmp = ListIterator(this->current);
  if (this->current->get_prev()->get_prev() != nullptr) {
    this->current = this->current->get_prev();
  } else {
    auto curr = this->current;
    for (; curr->get_next() != nullptr; curr = curr->get_next()) {
    }
    this->current = curr;
  }
  return tmp;
}

template <typename T>
bool ListIterator<T>::operator==(const ListIterator<T>& rhs) {
  return this->current == rhs.current;
}

template <typename T>
bool ListIterator<T>::operator!=(const ListIterator<T>& rhs) {
  return this->current != rhs.current;
}

template <typename T>
class ListConstIterator {
 public:
  // using value_type = T;
  // using reference = value_type&;
  // using const_reference = const value_type&;
  // using iterator = ListIterator;
  using size_type = std::size_t;

 public:
  const ListNode<T>* current;

 public:
  // constructor with address parametr
  ListConstIterator(ListNode<T>* address);

  // // Copy constructor
  // ListIterator(const ListIterator &other);

  // // Move constructor
  // ListIterator(ListIterator &&other);

  // Destructor
  ~ListConstIterator() {}

  // // Copy assignment operator(=).
  // ListIterator<T>& operator=(const ListIterator<T> &rhs);

  // // Move assignment operator(=).
  // ListIterator<T>& operator=(ListIterator<T> && rhs);

  T& operator*();

  // // prefix ++
  // ListIterator<T>& operator++();

  // // postfix ++
  // ListIterator<T> operator++(int);

  // // prefix --
  // ListIterator<T>& operator--();

  // // postfix --
  // ListIterator<T> operator--(int);

  bool operator==(const ListConstIterator<T>& rhs);
  // bool operator!=(const ListIterator<T> &rhs);
};

template <typename T>
ListConstIterator<T>::ListConstIterator(ListNode<T>* address) {
  this->current = address;
}

template <typename T>
T& ListConstIterator<T>::operator*() {
  return this->current->value_;
}

template <typename T>
bool ListConstIterator<T>::operator==(const ListConstIterator<T>& rhs) {
  return this->current == rhs.current;
}

}  // namespace s21

#endif
