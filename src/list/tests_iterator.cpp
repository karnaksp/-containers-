#include <iostream>

#include <list>

int main () {
    std::list l1 {1,2,3,4,5,6,7,8,9};
    auto it = l1.begin();
    std::cout << &*it << std::endl;
    it--;
    std::cout << &*it << std::endl;
    it = l1.end();
    std::cout << &*it << std::endl;
    it++;
    std::cout << &*it << std::endl;



    return 0;
}