#ifndef S21_ITERATOR
#define S21_ITERATOR

#include <cstddef>

#include "s21_node.h"

namespace s21 {
    class ListIterator {
public:
    using value_type = int;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = ListIterator;
    using size_type = std::size_t;
    
private:
    Node* current;
public:
    // constructor with address parametr
    ListIterator(Node* address);

    // Copy constructor
    ListIterator(const ListIterator &other);

    // Move constructor
    ListIterator(ListIterator &&other);

    // Destructor
    ~ListIterator(){}

    // Copy assignment operator(=).
    ListIterator& operator=(const ListIterator &rhs);

    // Move assignment operator(=).
    ListIterator& operator=(ListIterator && rhs);

    
    value_type& operator*();

    // prefix ++
    ListIterator& operator++();  

    // postfix ++
    ListIterator operator++(int);  

    // prefix --
    ListIterator& operator--();  

    // postfix --
    ListIterator operator--(int); 

    bool operator==(const ListIterator &rhs);
    bool operator!=(const ListIterator &rhs);
};


class ListConstIterator {
};

}

#endif


