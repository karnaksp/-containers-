#ifndef S21_STACK_H
#define S21_STACK_H

#include <cstddef>
#include <initializer_list>
#include <limits>

#include "../list/s21_list.h"
#include "../list/s21_node.h"
#include "../list/s21_iterator.h"

namespace s21 {

using size_type = std::size_t;

template<typename T>
class Stack{
private:
    List<T> stack_;

public:
           /**********************************
            *
            *   Stack Helper Functions
            * 
            ***********************************/
    void print_all();


            /**********************************
            *
            *   Stack Member functions
            * 
            ***********************************/ 

    // default constructor, creates an empty queue
    Stack();

    // initializer list constructor, creates queue 
    // initizialized using std::initializer_list
    Stack(std::initializer_list<T> const &items);

    // copy constructor
    Stack(const Stack<T> &s);

    // move constructor
    Stack(Stack &&s);

    // destructor
    ~Stack();

    // assignment operator overload for moving an object
    Stack<T> operator=(Stack &&s);



            /**********************************
            *
            *   Stack Element access
            * 
            ***********************************/ 

    // accesses the top element
    const T& top();

            /**********************************
            *
            *   Stack Capacity
            * 
            ***********************************/ 

    // checks whether the container is empty
    bool empty();

    // returns the number of elements
    size_type size();
    
            /**********************************
            *
            *   Stack Modifiers
            * 
            ***********************************/ 

    // inserts an element at the end
    void push(const T& value);

    // removes the first element
    void pop();

    // swaps the contents
    void swap(Stack& other);

};


}

#endif