#include <iostream>
#include <list>

#include <vector>
#include <typeinfo>

#include <limits>
#include <algorithm>
void print_list(std::list<int> vec2) {
    int i {0};
    for (auto it = vec2.begin(); it != vec2.end(); it++) {
        std::cout << i++ << ": " << *it << " | " <<  &*it  << std::endl;
    }
    std::cout << "end(): "<< &*vec2.end() << std::endl;
}

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
std::cout << "begin(): " << *vec.begin() << std::endl ;
std::cout << "end():   " << *vec.end() << std::endl ;
std::cout << "&*vec.begin(): "<< &*vec.begin() << std::endl ;
std::cout << "&*vec.end():   "<< &*vec.end() << std::endl ;

/*
Initializing iterators

std::vector<int> vec {1,2,3};

std::vector<int>::iterator it = vec.begin();

or

auto it = vec.begin();
*/

/*
Operations with iterators (it)
++it
it++
it = it1
*it
it->
it == it1
it != it1
--it
it--
it + i ; it += i ; it - i; it -= i;
it < it1 ; it <= it1; it > it1; it >= it1;
*/

/*
Using iterators - std::vector

std::vector<int> vec {1,2,3};

std::vector<int>::iterator it = vec.begin();

while (it != vec.end()) {
    std::cout << *it << " ";
    ++it;
}
// 1 2 3
*/
std::cout << "\n\tUsing iterators" << std::endl;
std::vector<int> vec1 {1,2,3};
std::vector<int>::iterator it = vec1.begin();
while (it != vec1.end()) {
    std::cout << *it << " " << std::endl;
    std::cout << &*it << " " << std::endl;

    ++it;
    if (vec1.end() == it) {
        std::cout << &*it << std::endl;
    }
}
std::cout << "\n";


/*
range for loop
*/
std::cout << "\n\tUsing iterators - range for loop" << std::endl;
std::vector<int> vec2 {1,2,3};
for (auto it = vec2.begin(); it != vec2.end(); it++) {
    std::cout << *it << " " << std::endl;
    std::cout << &*it << " " << std::endl;
    if (vec2.end() == it + 1) {
        std::cout << &*vec2.end() << std::endl;
    }
}
std::cout << "\n";


// 835 pdf

/*
std::list

list is bidirectional (doubly-linked)

Rapid insertion and deletion of elements 
anywhere in the container (constant time)
*/

std::cout << "\n\tList" << std::endl;
std::list<int> list_1 {1,2,3,4,5};
std::cout << *list_1.begin() << std::endl;
std::cout << *list_1.end() << std::endl;
std::cout << "First element: " << list_1.front() << std::endl;
std::cout << "Last element:  " << list_1.back() << std::endl;
std::cout << "Size        :  " << list_1.size() << std::endl;
list_1.push_back(6);  // add to the back
list_1.pop_back();    // remove from the back
list_1.push_front(-1); // add to the front
list_1.pop_front();    // remove element from the front
std::cout << "My max size : " << std::numeric_limits<std::size_t>::max() / (sizeof(int) * 8 + 2 * sizeof(int*) ) << std::endl;
std::cout << "std max size: "<< list_1.max_size() << std::endl;
std::cout << "Size of 1 element of list: "<< sizeof(list_1) << std::endl;
std::cout << "Size of 1 element of int : "<< sizeof(list_1.front()) << std::endl;
std::cout << "Size of 1 element of it  : "<< sizeof(list_1.begin()) << std::endl;

print_list(list_1);

std::cout << "\n\tPractice with List" << std::endl;
std::list<int> list_2 {1, 2, 3, 4};
list_2.push_front(-10);
list_2.push_back(10);
print_list(list_2);

std::cout << "\n\tPractice with List insert" << std::endl;
std::list<int> list_3 {1,2,3,4,5};
auto it2 = std::find(list_3.begin(), list_3.end(), 3);
list_3.insert(it2, 10);  // 1 2 10 3 4 5
list_3.erase(it2);       // erases the 3, 1 2 10 4 5
print_list(list_3);

std::cout << "\n\tPractice with List front and back" << std::endl;
std::list<char> list4;
auto m = list4.front();
std::cout << "Size: " << list4.size() << " . Value: " << m << std::endl; 

std::cout << "\n\tPractice with List iterators++" << std::endl;
std::list<int> list5 {1,2,3,4};
auto it5 = list5.begin();

std::cout << "++: " << *it5 << std::endl;

it5++;
std::cout << "++: " << *it5 << std::endl;
it5++;
std::cout << "++: " << *it5 << std::endl;
it5++;
std::cout << "++: " << *it5 << std::endl;
it5++;
std::cout << "++: " << *it5 << std::endl;
it5++;
std::cout << "++: " << *it5 << std::endl;
it5++;
std::cout << "++: " << *it5 << std::endl;
it5++;
std::cout << "++: " << *it5 << std::endl;

auto it5_pre = list5.begin();


auto list5_end = list5.end();
it5_pre--;
if (list5_end != it5_pre) {
    std::cout << "--: " << *it5_pre << std::endl;
}
it5_pre--;
if (list5_end != it5_pre) {
    std::cout << "--: " << *it5_pre << std::endl;
}
it5_pre--;
if (list5_end != it5_pre) {
    std::cout << "--: " << *it5_pre << std::endl;
}
it5_pre--;
if (list5_end != it5_pre) {
    std::cout << "--: " << *it5_pre << std::endl;
}
it5_pre--;
if (list5_end != it5_pre) {
    std::cout << "--: " << *it5_pre << std::endl;
}

return 0;
}