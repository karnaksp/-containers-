#include <iostream>
#include <list>

#include <typeinfo>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

template <class T>
T min(T a, T b) {  // we may also use class instead of typename
    return (a < b) ? a : b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b) {
    std::cout << a<< " " << b;
}

// func <int,double>(10,20.2);
// func('A', 12.4); // compiler can deduce type


/*
Generic Programming with class templates

template <typename T>
class Iten {
    private:
        std::string name;
        T value;
    public:
        Item(std::string name, T value)
            : name{name}, value{value}
        {}
        std::string get_name() const {return name;}
        T get_value() const {return value;}
};

Item<int> iten1 {"Larry", 1};

Item<double> item2 {"House", 1000.0};

Item<std::string> item3 {"Frank", "Boss"}

std::bector<Item<int>> vec;
*/

/*
template <typename T1, typename T2>
struct My_Pair {
    T1 first;
    T2 second
}

My_Pair <std::string, int> p1 {"Frank", 100};
My_Pair <int, double> p2 {124, 13.6};
std::vector<My_Pair<int, double>> vec;

*/

/*
#include <utility>

std::pair<std::string, int> p1 {"Frank", 100};

std::cout << p1.first;   // Frank
std::cout << p1.second;  // 100

*/

/*
operator<, operator== for Ordered associative containers
*/

int main() {
    std::list<int> l;
    
    std::cout << "\tEmpty list" << std::endl;
    std::cout << "Is empty: "<< std::boolalpha << l.empty()  << std::endl;
    std::cout << "Size: " << l.size()  << std::endl;
    std::cout << "Max size: " << l.max_size()  << std::endl;
    std::cout << "Front element: " << l.front()  << std::endl;
    std::cout << "Back element: " << l.back()  << std::endl;
    std::cout << "Pointer to list: " << &l  << std::endl;

    std::cout <<"\n\tTemplate" << std::endl;
    std::cout << "Max template: " << max<int>(5, 10) << std::endl;
    std::cout << "Max template: " << max(5, 10) << std::endl;  // compiler can deduce type
    std::cout << "Type of return of Max template: " << typeid(max<float>(5, 10)).name() << std::endl;
    std::cout << "Min template: " << min<bool>(6, 12) << std::endl;


    return 0;
}