#include "s21_containers_test.h"

namespace s21 {
namespace test {

// TEST(IteratorTest, Iteration) {
//   Node<int> n1(1), n2(2), n3(3);
//   n1.left = &n2;
//   n2.parent = &n1;
//   n1.right = &n3;
//   n3.parent = &n1;
//   Iterator<int> it_begin(&n1);
//   Iterator<int> it_end(nullptr);
//   int expected_value = 1;
//   for (auto it = it_begin; it != it_end; ++it) {
//     ASSERT_EQ(*it, expected_value);
//     ++expected_value;
//   }
// }

TEST(IteratorTest, Comparison) {
  Node<int> n1(1), n2(2);
  n1.left = &n2;
  n2.parent = &n1;
  Iterator<int> it1(&n1);
  Iterator<int> it2(&n1);
  Iterator<int> it3(&n2);
  ASSERT_EQ(it1, it2);
  ASSERT_NE(it1, it3);
}

TEST(IteratorTest, Access) {
  Node<int> n1(42);
  Iterator<int> it(&n1);
  ASSERT_EQ(*it, 42);
}

// TEST(ConstIteratorTest, Iteration) {
//   Node<int> n1(1), n2(2), n3(3);
//   n1.left = &n2;
//   n2.parent = &n1;
//   n1.right = &n3;
//   n3.parent = &n1;
//   ConstIterator<int> it_begin(&n1);
//   ConstIterator<int> it_end(nullptr);
//   int expected_value = 1;
//   for (auto it = it_begin; it != it_end; ++it) {
//     ASSERT_EQ(*it, expected_value);
//     ++expected_value;
//   }
// }

TEST(ConstIteratorTest, Comparison) {
  Node<int> n1(1), n2(2);
  n1.left = &n2;
  n2.parent = &n1;
  ConstIterator<int> it1(&n1);
  ConstIterator<int> it2(&n1);
  ConstIterator<int> it3(&n2);
  ASSERT_EQ(it1, it2);
  ASSERT_NE(it1, it3);
}

TEST(ConstIteratorTest, Access) {
  Node<int> n1(42);
  ConstIterator<int> it(&n1);
  ASSERT_EQ(*it, 42);
}

}  // namespace test
}  // namespace s21

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
