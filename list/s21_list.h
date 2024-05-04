#ifndef S21_LIST
#define S21_LIST

#include <cstddef>
#include <initializer_list>

namespace s21 {


class Node {
public:
    int value_;
    Node* next_;
    Node* prev_;

public:
    Node();
    
    void insert_node_after(int value);
    
    void delete_current_node();

    void print_node();

    // ~Node();

    void delete_all_nodes_curr_and_forward();
};

template<class T>
class ListIterator {
public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using iterator = ListIterator<T>;
    using size_type = size_t;
    
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
    ~ListIterator();

    // Copy assignment operator(=).
    ListIterator& operator=(const ListIterator &rhs);

    // Move assignment operator(=).
    ListIterator& operator=(ListIterator && rhs);

    
    value_type& operator*();

    // prefix ++
    ListIterator<T>& operator++();  

    // postfix ++
    ListIterator<T> operator++(const ListIterator<T> &self);  

    // prefix --
    ListIterator<T>& operator--();  

    // postfix --
    ListIterator<T> operator--(const ListIterator<T> &self); 

    bool operator==(const ListIterator<T> &rhs);
    bool operator!=(const ListIterator<T> &rhs);
};

template<class T>
class ListConstIterator {
};

template<class T>
class list {
public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using iterator = ListIterator<T>;
    using const_iterator = ListConstIterator<T>;
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
    
    friend void Node::insert_node(const Node& new_node);
    
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
    list(std::initializer_list<T> const &items);

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