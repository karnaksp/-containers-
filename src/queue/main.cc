#include <iostream>

#include "s21_queue.h"

int main () {

    std::cout << "Test" << std::endl;

    s21::Queue<int> my_queue = s21::Queue<int> {1,2,3};
    std::cout << "size(): " << my_queue.size() << std::endl;
    std::cout << "front(): " << my_queue.front() << std::endl;
    std::cout << "back(): " << my_queue.back() << std::endl;

    my_queue.push(5);
    my_queue.pop();
    my_queue.pop();
    my_queue.pop();

    std::cout << "front(): " << my_queue.front() << std::endl;
    std::cout << "back(): " << my_queue.back() << std::endl;
    std::cout << "empty: "<< std::boolalpha << my_queue.empty() << std::endl;

    my_queue.pop();

    std::cout << "empty: "  << my_queue.empty() << std::endl;

    my_queue.print_all();

    return 0;
}