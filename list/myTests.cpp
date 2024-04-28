#include <iostream>
#include <list>

#include <vector>
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

    std::cout <<"\n\tIterators" << std::endl;
/*
    Alows abstracting an arbitrary contaner as a sequence 
    of elements
    They are objects that work like pointers by design
    Most container classes can be traversed with iterators
*/

/*
Declaring iterators

Iterators must be declared based on the container type
they will iterate over

container_type::iterator_type iterator_name;

std::vector<int>::iterator it1;
std::list<std::string>::iterator it2
std::map<std::string, std::string>::iterator it3;
std::set<char>::iterator it4;

*/

/*
iterator begin and end methods
std::vector<int> vec {1,2,3};
vec.begin() - first element
vec.end() - location after last element
*/
std::vector<int> vec {1,2,3};
std::cout << *vec.begin() << std::endl ;
std::cout << *vec.end() << std::endl ;
std::cout << &*vec.begin() << std::endl ;
std::cout << &*vec.end() << std::endl ;

/*
Initializing iterators

std::vector<int> vec {1,2,3};

std::vector<int>::iterator it = vec.begin();

or

auto it = vec.begin();

*/


    return 0;
}