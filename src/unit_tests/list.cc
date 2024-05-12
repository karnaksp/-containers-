#include "tests.h"

namespace s21 {

TEST(s21_list_tests_construct, s21_list_tests_construct_01) {
    List<int> my_list;
    ASSERT_EQ(my_list.empty(), true);
    ASSERT_EQ(my_list.size(), 0);
}

TEST(s21_list_tests_construct, s21_list_tests_construct_02) {
    List<int> my_list {1,2,3,4,5,6};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 6);
    ASSERT_EQ(my_list.front(), 1);
    ASSERT_EQ(my_list.back(), 6);
}

TEST(s21_list_tests_construct, s21_list_tests_construct_03) {
    List<int> my_list1 {1,2,3,4,5,6};
    List<int> my_list (my_list1);
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 6);
    ASSERT_EQ(my_list.front(), 1);
    ASSERT_EQ(my_list.back(), 6);
}

TEST(s21_list_tests_construct, s21_list_tests_construct_04) {
    List<int> my_list =  List<int>{1,2,3,4,5,6};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 6);
    ASSERT_EQ(my_list.front(), 1);
    ASSERT_EQ(my_list.back(), 6);
}

TEST(s21_list_tests_front, s21_list_tests_front_01) {
    List<std::string> my_list {"One", "Two", "Three"};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 3);
    ASSERT_EQ(my_list.front(), "One");
    ASSERT_EQ(my_list.back(), "Three");
}

TEST(s21_list_tests_max_size, s21_list_tests_max_size_01) {
    List<std::string> my_list {"One", "Two", "Three"};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 3);
    ASSERT_EQ(my_list.front(), "One");
    ASSERT_EQ(my_list.back(), "Three");
    ASSERT_EQ(my_list.max_size(), 384307168202282324);
}

TEST(s21_list_tests_max_size, s21_list_tests_max_size_02) {
    List<int> my_list {6,5,4,3,2,1};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 6);
    ASSERT_EQ(my_list.front(), 6);
    ASSERT_EQ(my_list.back(), 1);
    ASSERT_EQ(my_list.max_size(), 768614336404564648);
}


TEST(s21_list_tests_methods, s21_list_tests_methods_01) {
    List<int> my_list {6,5,4,3,2,1};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 6);
    ASSERT_EQ(my_list.front(), 6);
    ASSERT_EQ(my_list.back(), 1);
    my_list.clear();
    ASSERT_EQ(my_list.size(), 0);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_02) {
    List<int> my_list {7,6,5,4,3,2,1,0};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 8);
    ASSERT_EQ(my_list.front(), 7);
    ASSERT_EQ(my_list.back(), 0);
    auto it = my_list.begin();
    ASSERT_EQ(my_list.front(), *it);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_03) {
    List<int> my_list {7,6,5,4,3,2,1,0};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 8);
    ASSERT_EQ(my_list.front(), 7);
    ASSERT_EQ(my_list.back(), 0);
    auto it = my_list.begin();
    it++;
    ASSERT_EQ(6, *it);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_04) {
    List<int> my_list {7,6,5,4,3,2,1,0};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 8);
    ASSERT_EQ(my_list.front(), 7);
    ASSERT_EQ(my_list.back(), 0);
    auto it = my_list.begin();
    ++it;
    ASSERT_EQ(6, *it);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_05) {
    List<int> my_list {7,6,5,4,3,2,1,0};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 8);
    ASSERT_EQ(my_list.front(), 7);
    ASSERT_EQ(my_list.back(), 0);
    auto it = my_list.begin();
    ++it;
    ++it;
    ASSERT_EQ(5, *it);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_06) {
    List<int> my_list {7,6,5,4,3,2,1,0};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 8);
    ASSERT_EQ(my_list.front(), 7);
    ASSERT_EQ(my_list.back(), 0);
    auto it = my_list.begin();
    ++it;
    ++it;
    ++it;
    ASSERT_EQ(4, *it);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_07) {
    List<int> my_list {7,6,5,4,3,2,1,0};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 8);
    ASSERT_EQ(my_list.front(), 7);
    ASSERT_EQ(my_list.back(), 0);
    auto it = my_list.begin();
    ++it;
    ++it;
    ++it;
    --it;
    ASSERT_EQ(5, *it);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_08) {
    List<int> my_list {7,6,5,4,3,2,1,0};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 8);
    ASSERT_EQ(my_list.front(), 7);
    ASSERT_EQ(my_list.back(), 0);
    auto it = my_list.end();
    --it;
    ASSERT_EQ(0, *it);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_09) {
    List<int> my_list {7,6,5,4,3,2,1,0};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 8);
    ASSERT_EQ(my_list.front(), 7);
    ASSERT_EQ(my_list.back(), 0);
    auto it = my_list.begin();
    my_list.insert(it, 10);
    ASSERT_EQ(my_list.front(), 10);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_10) {
    List<int> my_list {7,6,5,4,3,2,1,0};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 8);
    ASSERT_EQ(my_list.front(), 7);
    ASSERT_EQ(my_list.back(), 0);
    auto it = my_list.begin();
    my_list.erase(it);
    ASSERT_EQ(my_list.front(), 6);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_11) {
    List<int> my_list {7,6,5,4,3,2,1,0};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 8);
    ASSERT_EQ(my_list.front(), 7);
    ASSERT_EQ(my_list.back(), 0);
    my_list.push_front(10);
    ASSERT_EQ(my_list.front(), 10);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_12) {
    List<int> my_list {7,6,5,4,3,2,1,0};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 8);
    ASSERT_EQ(my_list.front(), 7);
    ASSERT_EQ(my_list.back(), 0);
    my_list.push_back(10);
    ASSERT_EQ(my_list.back(), 10);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_13) {
    List<int> my_list {7,6,5,4,3,2,1,0};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 8);
    ASSERT_EQ(my_list.front(), 7);
    ASSERT_EQ(my_list.back(), 0);
    my_list.pop_back();
    ASSERT_EQ(my_list.back(), 1);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_14) {
    List<int> my_list {7,6,5,4,3,2,1,0};
    ASSERT_EQ(my_list.empty(), false);
    ASSERT_EQ(my_list.size(), 8);
    ASSERT_EQ(my_list.front(), 7);
    ASSERT_EQ(my_list.back(), 0);
    my_list.pop_front();
    ASSERT_EQ(my_list.front(), 6);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_15) {
    List<int> my_list {7,6,5,4,3,2,1,0};
    List<int> my_list1 {10,20,30};
    my_list.swap(my_list1);
    ASSERT_EQ(my_list.size(), 3);
    ASSERT_EQ(my_list.front(), 10);
    ASSERT_EQ(my_list.back(), 30);
    ASSERT_EQ(my_list1.size(), 8);
    ASSERT_EQ(my_list1.front(), 7);
    ASSERT_EQ(my_list1.back(), 0);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_16) {
    List<int> my_list {5,10, 4, 100, 3,2,1, 1000, -6};
    my_list.sort();
    ASSERT_EQ(my_list.front(), -6);
    ASSERT_EQ(my_list.back(), 1000);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_17) {
    List<std::string> my_list {"Can", "Allo", "Two"};
    my_list.sort();
    ASSERT_EQ(my_list.front(), "Allo");
    ASSERT_EQ(my_list.back(), "Two");
}

TEST(s21_list_tests_methods, s21_list_tests_methods_18) {
    List<int> my_list {5,10, 4, 100, 3,2,1, 1000, -6};
    List<int> my_list1 {-100,-10,-11};
    my_list.sort();
    my_list1.sort();
    my_list.merge(my_list1);
    ASSERT_EQ(my_list.front(), -100);
    auto it = my_list.begin();
    ASSERT_EQ(*it++, -100);
    ASSERT_EQ(*it++, -11);
    ASSERT_EQ(*it++, -10);
    ASSERT_EQ(*it++, -6);
    ASSERT_EQ(*it++, 1);
    ASSERT_EQ(my_list.back(), 1000);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_19) {
    List<int> my_list {5,10, 4, 100, 3,2,1, 1000, -6};
    List<int> my_list1 {-100,-10,-11};
    auto it = my_list.begin();
    it++;
    it++;
    it++;
    ASSERT_EQ(my_list.size(), 9);
    my_list.splice(it, my_list1);
    ASSERT_EQ(my_list.size(), 12);
    auto it1 = my_list.begin();
    ASSERT_EQ(*it1++, 5);
    ASSERT_EQ(*it1++, 10);
    ASSERT_EQ(*it1++, 4);
    ASSERT_EQ(*it1++, -100);
    ASSERT_EQ(*it1++, -10);
    ASSERT_EQ(*it1++, -11);
    ASSERT_EQ(*it1++, 100);
}

TEST(s21_list_tests_methods, s21_list_tests_methods_21) {
    List<int> my_list {1, 1, 1, 2, 3, 4, 4, 5, 6, 6, 7, 7, 8, 7, 8, 9};
    ASSERT_EQ(my_list.size(), 16);
    my_list.unique();
    ASSERT_EQ(my_list.size(), 11);
    ASSERT_EQ(my_list.size(), 11);
}


}  // namespace s21