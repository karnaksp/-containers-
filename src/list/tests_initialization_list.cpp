#include <initializer_list>
#include <string>
#include <iostream>

int main() {
    std::initializer_list<int> list {1,2,3,4,5,6};
    std::cout << "Size: " << list.size() << std::endl;

    for(auto it = list.begin(); it != list.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << std::boolalpha << empty(list) << std::endl;

    std::initializer_list<int> list1;
    std::cout << std::boolalpha << empty(list1) << std::endl;



    return 0;
}