#include "tests.h"

namespace s21 {

TEST(VectorTest, DefaultConstructor1) {
  Vector<int> vec;
  EXPECT_EQ(vec.Size(), 0);
  EXPECT_EQ(vec.Capacity(), 0);
}

TEST(VectorTest, DefaultConstructor3) {
  Vector<int> vec;
  EXPECT_EQ(vec.Size(), 0);
  EXPECT_EQ(vec.Capacity(), 0);
}

TEST(VectorTest, DefaultConstructor4) {
  Vector<double> vec;
  EXPECT_EQ(vec.Size(), 0);
  EXPECT_EQ(vec.Capacity(), 0);
}

TEST(VectorTest, DefaultConstructor5) {
  Vector<std::string> vec;
  EXPECT_EQ(vec.Size(), 0);
  EXPECT_EQ(vec.Capacity(), 0);
}

TEST(VectorTest, DefaultConstructor6) {
  Vector<int> vec;
  EXPECT_EQ(vec.Size(), 0);
  EXPECT_EQ(vec.Capacity(), 0);
  Vector<int> anotherVec;
  EXPECT_EQ(anotherVec.Size(), 0);
  EXPECT_EQ(anotherVec.Capacity(), 0);
}

TEST(VectorTest, SizeConstructor1) {
  size_t Size = 5;
  Vector<int> vec(Size);
  EXPECT_EQ(vec.Size(), Size);
  EXPECT_GE(vec.Capacity(), Size);
  for (size_t i = 0; i < Size; ++i) {
    EXPECT_EQ(vec[i], int());
  }
}

TEST(VectorTest, SizeConstructor2) {
  size_t Size = 5;
  Vector<double> vec(Size);
  EXPECT_EQ(vec.Size(), Size);
  EXPECT_GE(vec.Capacity(), Size);
  for (size_t i = 0; i < Size; ++i) {
    EXPECT_EQ(vec[i], double());
  }
}

TEST(VectorTest, SizeConstructor3) {
  size_t Size = 3;
  Vector<std::string> vec(Size);
  EXPECT_EQ(vec.Size(), Size);
  EXPECT_GE(vec.Capacity(), Size);
  for (size_t i = 0; i < Size; ++i) {
    EXPECT_EQ(vec[i], std::string());
  }
}

TEST(VectorTest, SizeConstructor4) {
  size_t Size = 10;
  Vector<int> vec(Size);
  EXPECT_EQ(vec.Size(), Size);
  EXPECT_GE(vec.Capacity(), Size);
}

TEST(VectorTest, SizeConstructor5) {
  size_t Size = 1000;
  Vector<int> vec(Size);
  EXPECT_EQ(vec.Size(), Size);
  EXPECT_GE(vec.Capacity(), Size);
  for (size_t i = 0; i < Size; ++i) {
    EXPECT_EQ(vec[i], int());
  }
}

TEST(VectorTest, SizeConstructor6) {
  Vector<int> vec(0);
  EXPECT_EQ(vec.Size(), 0);
  EXPECT_EQ(vec.Capacity(), 0);
}

TEST(VectorTest, CopyConstructor1) {
  Vector<int> vec1(5);
  for (size_t i = 0; i < 5; ++i) {
    vec1[i] = static_cast<int>(i);
  }
  Vector<int> vec2 = vec1;
  EXPECT_EQ(vec2.Size(), vec1.Size());
  EXPECT_EQ(vec2.Capacity(), vec1.Capacity());
  for (size_t i = 0; i < vec2.Size(); ++i) {
    EXPECT_EQ(vec2[i], vec1[i]);
  }
}

TEST(VectorTest, CopyConstructor2) {
  Vector<double> vec1(5);
  for (size_t i = 0; i < 5; ++i) {
    vec1[i] = static_cast<double>(i) + 0.5;
  }
  Vector<double> vec2 = vec1;
  EXPECT_EQ(vec2.Size(), vec1.Size());
  EXPECT_EQ(vec2.Capacity(), vec1.Capacity());
  for (size_t i = 0; i < vec2.Size(); ++i) {
    EXPECT_EQ(vec2[i], vec1[i]);
  }
}

TEST(VectorTest, CopyConstructor3) {
  Vector<std::string> vec1(3);
  vec1[0] = "Hello";
  vec1[1] = "World";
  vec1[2] = "Test";

  Vector<std::string> vec2 = vec1;

  EXPECT_EQ(vec2.Size(), vec1.Size());
  EXPECT_EQ(vec2.Capacity(), vec1.Capacity());
  for (size_t i = 0; i < vec2.Size(); ++i) {
    EXPECT_EQ(vec2[i], vec1[i]);
  }
}

TEST(VectorTest, CopyConstructor4) {
  Vector<int> vec1;
  Vector<int> vec2 = vec1;
  EXPECT_EQ(vec2.Size(), 0);
  EXPECT_EQ(vec2.Capacity(), 0);
}

TEST(VectorTest, CopyConstructor5) {
  Vector<int> vec1(1000);
  for (size_t i = 0; i < 1000; ++i) {
    vec1[i] = static_cast<int>(i);
  }
  Vector<int> vec2 = vec1;
  EXPECT_EQ(vec2.Size(), vec1.Size());
  EXPECT_EQ(vec2.Capacity(), vec1.Capacity());
  for (size_t i = 0; i < vec2.Size(); ++i) {
    EXPECT_EQ(vec2[i], vec1[i]);
  }
}

TEST(VectorTest, CopyConstructor6) {
  Vector<int> vec1(3);
  vec1[0] = 1;
  vec1[1] = 2;
  vec1[2] = 3;
  Vector<int> vec2 = vec1;
  vec1[0] = 4;
  vec1[1] = 5;
  vec1[2] = 6;
  EXPECT_EQ(vec2[0], 1);
  EXPECT_EQ(vec2[1], 2);
  EXPECT_EQ(vec2[2], 3);
}

TEST(VectorTest, MoveConstructor1) {
  Vector<int> vec1(5);
  for (size_t i = 0; i < 5; ++i) {
    vec1[i] = static_cast<int>(i);
  }
  Vector<int> vec2 = std::move(vec1);
  EXPECT_EQ(vec2.Size(), 5);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(vec2[i], static_cast<int>(i));
  }
  EXPECT_EQ(vec1.Size(), 0);
  EXPECT_EQ(vec1.Capacity(), 0);
}

TEST(VectorTest, MoveConstructor2) {
  Vector<double> vec1(5);
  for (size_t i = 0; i < 5; ++i) {
    vec1[i] = static_cast<double>(i) + 0.5;
  }
  Vector<double> vec2 = std::move(vec1);
  EXPECT_EQ(vec2.Size(), 5);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(vec2[i], static_cast<double>(i) + 0.5);
  }
  EXPECT_EQ(vec1.Size(), 0);
  EXPECT_EQ(vec1.Capacity(), 0);
}

TEST(VectorTest, MoveConstructor3) {
  Vector<std::string> vec1(3);
  vec1[0] = "Hello";
  vec1[1] = "World";
  vec1[2] = "Test";
  Vector<std::string> vec2 = std::move(vec1);
  EXPECT_EQ(vec2.Size(), 3);
  EXPECT_EQ(vec2[0], "Hello");
  EXPECT_EQ(vec2[1], "World");
  EXPECT_EQ(vec2[2], "Test");
  EXPECT_EQ(vec1.Size(), 0);
  EXPECT_EQ(vec1.Capacity(), 0);
}

TEST(VectorTest, MoveConstructor4) {
  Vector<int> vec1;
  Vector<int> vec2 = std::move(vec1);

  EXPECT_EQ(vec2.Size(), 0);
  EXPECT_EQ(vec2.Capacity(), 0);
  EXPECT_EQ(vec1.Size(), 0);
  EXPECT_EQ(vec1.Capacity(), 0);
}

TEST(VectorTest, MoveConstructor5) {
  Vector<int> vec1(1000);
  for (size_t i = 0; i < 1000; ++i) {
    vec1[i] = static_cast<int>(i);
  }
  Vector<int> vec2 = std::move(vec1);
  EXPECT_EQ(vec2.Size(), 1000);
  for (size_t i = 0; i < 1000; ++i) {
    EXPECT_EQ(vec2[i], static_cast<int>(i));
  }
  EXPECT_EQ(vec1.Size(), 0);
  EXPECT_EQ(vec1.Capacity(), 0);
}

TEST(VectorTest, iter1) {
  Vector<int> vec(5);
  for (size_t i = 0; i < 5; ++i) {
    vec[i] = static_cast<int>(i);
  }
  auto it = vec.begin();
  auto end = vec.end();
  EXPECT_EQ(std::distance(it, end), 5);
  for (int i = 0; it != end; ++it, ++i) {
    EXPECT_EQ(*it, i);
  }
}

TEST(VectorTest, iter2) {
  Vector<int> vec(5);
  for (size_t i = 0; i < 5; ++i) {
    vec[i] = static_cast<int>(i);
  }
  auto it = vec.cbegin();
  auto end = vec.cend();
  EXPECT_EQ(std::distance(it, end), 5);
  for (int i = 0; it != end; ++it, ++i) {
    EXPECT_EQ(*it, i);
  }
}

TEST(VectorTest, iter3) {
  Vector<int> vec;
  auto it = vec.begin();
  auto end = vec.end();
  EXPECT_EQ(std::distance(it, end), 0);
  EXPECT_EQ(it, end);
}

TEST(VectorTest, iter4) {
  Vector<int> vec;
  auto it = vec.cbegin();
  auto end = vec.cend();
  EXPECT_EQ(std::distance(it, end), 0);
  EXPECT_EQ(it, end);
}

TEST(VectorTest, iter5) {
  Vector<std::string> vec(3);
  vec[0] = "Hello";
  vec[1] = "World";
  vec[2] = "Test";
  auto it = vec.begin();
  auto end = vec.end();
  EXPECT_EQ(std::distance(it, end), 3);
  EXPECT_EQ(*it, "Hello");
  ++it;
  EXPECT_EQ(*it, "World");
  ++it;
  EXPECT_EQ(*it, "Test");
}

TEST(VectorTest, iter6) {
  Vector<std::string> vec(3);
  vec[0] = "Hello";
  vec[1] = "World";
  vec[2] = "Test";
  auto it = vec.cbegin();
  auto end = vec.cend();
  EXPECT_EQ(std::distance(it, end), 3);
  EXPECT_EQ(*it, "Hello");
  ++it;
  EXPECT_EQ(*it, "World");
  ++it;
  EXPECT_EQ(*it, "Test");
}

TEST(VectorTest, iter7) {
  const Vector<int> vec(5);
  auto it = vec.begin();
  auto end = vec.end();

  EXPECT_EQ(std::distance(it, end), 5);
}

TEST(VectorTest, iter8) {
  const Vector<int> vec(5);
  auto it = vec.cbegin();
  auto end = vec.cend();

  EXPECT_EQ(std::distance(it, end), 5);
}

TEST(VectorTest, Swap1) {
  Vector<int> vec1(5);
  for (size_t i = 0; i < 5; ++i) {
    vec1[i] = static_cast<int>(i);
  }
  Vector<int> vec2(3);
  for (size_t i = 0; i < 3; ++i) {
    vec2[i] = static_cast<int>(i + 10);
  }
  vec1.Swap(vec2);
  EXPECT_EQ(vec1.Size(), 3);
  EXPECT_EQ(vec2.Size(), 5);
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_EQ(vec1[i], static_cast<int>(i + 10));
  }
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(vec2[i], static_cast<int>(i));
  }
}

TEST(VectorTest, Swap2) {
  Vector<std::string> vec1(3);
  vec1[0] = "Hello";
  vec1[1] = "World";
  vec1[2] = "Test";
  Vector<std::string> vec2(2);
  vec2[0] = "One";
  vec2[1] = "Two";
  vec1.Swap(vec2);
  EXPECT_EQ(vec1.Size(), 2);
  EXPECT_EQ(vec2.Size(), 3);
  EXPECT_EQ(vec1[0], "One");
  EXPECT_EQ(vec1[1], "Two");
  EXPECT_EQ(vec2[0], "Hello");
  EXPECT_EQ(vec2[1], "World");
  EXPECT_EQ(vec2[2], "Test");
}

TEST(VectorTest, Swap3) {
  Vector<int> vec1;
  Vector<int> vec2;
  vec1.Swap(vec2);
  EXPECT_EQ(vec1.Size(), 0);
  EXPECT_EQ(vec2.Size(), 0);
}

TEST(VectorTest, Swap4) {
  Vector<int> vec1(1);
  vec1[0] = 42;
  Vector<int> vec2;
  vec1.Swap(vec2);
  EXPECT_EQ(vec1.Size(), 0);
  EXPECT_EQ(vec2.Size(), 1);
  EXPECT_EQ(vec2[0], 42);
}

TEST(VectorTest, Reserve1) {
  Vector<int> vec(5);
  for (size_t i = 0; i < 5; ++i) {
    vec[i] = static_cast<int>(i);
  }
  size_t old_capacity = vec.Capacity();
  vec.Reserve(10);
  EXPECT_GT(vec.Capacity(), old_capacity);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(vec[i], static_cast<int>(i));
  }
}

TEST(VectorTest, Reserve2) {
  Vector<int> vec(5);
  for (size_t i = 0; i < 5; ++i) {
    vec[i] = static_cast<int>(i);
  }
  size_t old_capacity = vec.Capacity();
  vec.Reserve(3);
  EXPECT_EQ(vec.Capacity(), old_capacity);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(vec[i], static_cast<int>(i));
  }
}

TEST(VectorTest, Reserve3) {
  Vector<int> vec;
  vec.Reserve(10);
  EXPECT_EQ(vec.Capacity(), 10);
}

TEST(VectorTest, Reserve4) {
  Vector<int> vec(5);
  for (size_t i = 0; i < 5; ++i) {
    vec[i] = static_cast<int>(i);
  }
  size_t old_capacity = vec.Capacity();
  vec.Reserve(5);
  EXPECT_EQ(vec.Capacity(), old_capacity);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(vec[i], static_cast<int>(i));
  }
}

TEST(VectorTest, Resize1) {
  Vector<int> vec(5);
  for (size_t i = 0; i < 5; ++i) {
    vec[i] = static_cast<int>(i);
  }
  vec.Resize(3);
  EXPECT_EQ(vec.Size(), 3);
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_EQ(vec[i], static_cast<int>(i));
  }
}

TEST(VectorTest, Resize2) {
  Vector<int> vec(5);
  for (size_t i = 0; i < 5; ++i) {
    vec[i] = static_cast<int>(i);
  }
  vec.Resize(5);
  EXPECT_EQ(vec.Size(), 5);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(vec[i], static_cast<int>(i));
  }
}

TEST(VectorTest, Resize3) {
  Vector<int> vec(3);
  for (size_t i = 0; i < 3; ++i) {
    vec[i] = static_cast<int>(i);
  }
  vec.Resize(5);
  EXPECT_EQ(vec.Size(), 5);
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_EQ(vec[i], static_cast<int>(i));
  }
  for (size_t i = 3; i < 5; ++i) {
    EXPECT_EQ(vec[i], 0);
  }
}

TEST(VectorTest, Resize4) {
  Vector<int> vec(10);
  for (size_t i = 0; i < 10; ++i) {
    vec[i] = static_cast<int>(i);
  }
  size_t old_capacity = vec.Capacity();
  vec.Resize(5);
  EXPECT_EQ(vec.Size(), 5);
  EXPECT_EQ(vec.Capacity(), old_capacity);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(vec[i], static_cast<int>(i));
  }
}

TEST(VectorTest, Resize5) {
  Vector<int> vec(5);
  for (size_t i = 0; i < 5; ++i) {
    vec[i] = static_cast<int>(i);
  }
  size_t old_capacity = vec.Capacity();
  vec.Resize(10);
  EXPECT_EQ(vec.Size(), 10);
  EXPECT_GT(vec.Capacity(), old_capacity);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(vec[i], static_cast<int>(i));
  }
}

TEST(VectorTest, Resize6) {
  Vector<int> vec;
  vec.Resize(5);
  EXPECT_EQ(vec.Size(), 5);
  EXPECT_EQ(vec.Capacity(), 5);
}

TEST(VectorTest, PushBack1) {
  Vector<int> vec;
  vec.PushBack(42);
  EXPECT_EQ(vec.Size(), 1);
  EXPECT_EQ(vec[0], 42);
}

TEST(VectorTest, PushBack2) {
  Vector<int> vec(3);
  vec[0] = 10;
  vec[1] = 20;
  vec[2] = 30;
  vec.PushBack(40);
  EXPECT_EQ(vec.Size(), 4);
  EXPECT_EQ(vec[3], 40);
}

TEST(VectorTest, Emplace1) {
  Vector<std::string> vec;
  auto it = vec.Emplace(vec.begin(), "Hello");
  EXPECT_EQ(vec.Size(), 1);
  EXPECT_EQ(*it, "Hello");
}

TEST(VectorTest, Emplace2) {
  Vector<int> vec(3);
  vec[0] = 10;
  vec[1] = 20;
  vec[2] = 30;
  auto it = vec.Emplace(vec.begin() + 1, 15);
  EXPECT_EQ(vec.Size(), 4);
  EXPECT_EQ(*it, 15);
  EXPECT_EQ(vec[0], 10);
  EXPECT_EQ(vec[1], 15);
  EXPECT_EQ(vec[2], 20);
  EXPECT_EQ(vec[3], 30);
}

TEST(VectorTest, InsertCopy) {
  Vector<int> vec(3);
  vec[0] = 10;
  vec[1] = 20;
  vec[2] = 30;

  auto it = vec.Insert(vec.begin() + 1, 15);

  EXPECT_EQ(vec.Size(), 4);
  EXPECT_EQ(*it, 15);
  EXPECT_EQ(vec[0], 10);
  EXPECT_EQ(vec[1], 15);
  EXPECT_EQ(vec[2], 20);
  EXPECT_EQ(vec[3], 30);
}

TEST(VectorTest, PopBack1) {
  Vector<int> vec;
  vec.PushBack(42);
  vec.PopBack();
  EXPECT_EQ(vec.Size(), 0);
}

TEST(VectorTest, PopBack2) {
  Vector<int> vec;
  vec.PushBack(10);
  vec.PushBack(20);
  vec.PushBack(30);

  vec.PopBack();

  EXPECT_EQ(vec.Size(), 2);
  EXPECT_EQ(vec[0], 10);
  EXPECT_EQ(vec[1], 20);
}

TEST(VectorTest, Erase1) {
  Vector<int> vec;
  vec.PushBack(42);
  auto it = vec.Erase(vec.begin());
  EXPECT_EQ(vec.Size(), 0);
  EXPECT_EQ(it, vec.end());
}

TEST(VectorTest, Erase2) {
  Vector<int> vec;
  vec.PushBack(10);
  vec.PushBack(20);
  vec.PushBack(30);
  auto it = vec.Erase(vec.begin() + 1);
  EXPECT_EQ(vec.Size(), 2);
  EXPECT_EQ(vec[0], 10);
  EXPECT_EQ(vec[1], 30);
  EXPECT_EQ(*it, 30);
}

}  // namespace s21
