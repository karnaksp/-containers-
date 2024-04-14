#ifndef S21_SET_H_
#define S21_SET_H_

namespace s21 {
template <class Key>
class set {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using size_type = std::size_t;
  using const_reference = const value_type &;

 public:
  set();

 private:
};
}  // namespace s21
#include "s21_set.tcc"
#endif  // S21_SET_H_
