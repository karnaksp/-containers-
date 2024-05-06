#ifndef S21_LIST
#define S21_LIST

#include <cstddef>
#include <initializer_list>

#include "s21_iterator.h"
#include "s21_node.h"

namespace s21 {

class list {
public:
    using value_type = int;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = ListIterator;
    using const_iterator = ListConstIterator;
    using size_type = std::size_t;
private:
    Node* head_;
    Node* tail_;
    Node* pre_head_;
    Node* post_tail_;
    size_type size_;

public:    
         /**********************************
            *
            *   List Helper Functions
            * 
            ***********************************/
    
    friend void Node::insert_node_before_curr(int value);
    
    friend void Node::delete_current_node();

            /**********************************
            *
            *   List Functions
            * 
            ***********************************/ 

    // default constructor, creates an empty list
    list();

    // parameterized constructor, creates the list of size n
    list(size_type n);

    /*
    initializer list constructor, 
    creates a list initizialized using std::initializer_list
    */
    list(std::initializer_list<value_type> const &items);

    // copy constructor
    list(const list &l);

    // move constructor
    list(list &&l);

    // destructor
    ~list();

    // assignment operator overload for moving an object
    list operator=(list &&l);

            /**********************************
            *
            *   List Element access
            * 
            ***********************************/ 

    // access the first element
    const_reference front();

    // access the last element
    const_reference back();
 
            /**********************************
            *
            *   List Iterators
            * 
            ***********************************/ 

    // returns an iterator to the beginning
    iterator begin();

    // returns an iterator to the end
    iterator end(); 
 
            /**********************************
            *
            *   List Capacity
            * 
            ***********************************/ 

    // checks whether the container is empty
    bool empty();

    // returns the number of elements
    size_type size();

    // returns the maximum possible number of elements
    size_type max_size();
          
            /**********************************
            *
            *   List Modifiers
            * 
            ***********************************/ 
    
    // clears the contents
    void clear();
    
    /*
    inserts element into concrete pos and 
    returns the iterator that points to the new element
    */
    iterator insert(iterator pos, const_reference value);
    
    // erases an element at pos
    void erase(iterator pos);
    
    // adds an element to the end
    void push_back(const_reference value);
    
    // removes the last element
    void pop_back();
    
    // adds an element to the head
    void push_front(const_reference value);
    
    // removes the first element
    void pop_front();
    
    // swaps the contents
    void swap(list& other);
    
    // merges two sorted lists
    void merge(list& other);
    
    // transfers elements from list other starting from pos
    void splice(const_iterator pos, list& other);
    
    // reverses the order of the elements
    void reverse();
    
    // removes consecutive duplicate elements
    void unique();
    
    // sorts the elements
    void sort();
};


}

#endif