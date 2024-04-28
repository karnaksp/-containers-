#include <iostream>
#include <list>



int main() {
    std::list<int> l;
    
    std::cout << "Empty list" << std::endl;
    std::cout << "Is empty: "<< std::boolalpha << l.empty()  << std::endl;
    std::cout << "Size: " << l.size()  << std::endl;
    std::cout << "Max size: " << l.max_size()  << std::endl;
    std::cout << "Front element: " << l.front()  << std::endl;
    std::cout << "Back element: " << l.back()  << std::endl;
    std::cout << "Pointer to list: " << &l  << std::endl;
    



    return 0;
}