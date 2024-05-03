#ifndef S21_LIST
#define S21_LIST

#include <cstddef>
#include <initializer_list>

namespace s21 {

template<class T>
struct Node {
    T value;
    Node* next;
    Node* prev;
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
    Node<T>* current;
public:
    value_type& operator*();
    ListIterator<T>& operator++();  // prefix
    ListIterator<T> operator++(const ListIterator<T> &self);  // postfix
    ListIterator<T>& operator--();  // prefix
    ListIterator<T> operator--(const ListIterator<T> &self); // postfix
    bool operator==(const ListIterator<T> &rhs);
    bool operator!=(const ListIterator<T> &rhs);
};

template<class T>
class ListConstIterator {
};

template<class T>
class list {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using iterator = ListIterator<T>;
    using const_iterator = ListConstIterator<T>;
    using size_type = size_t;

public:
    // List Functions
    list();
    list(size_type n);
    list(std::initializer_list<T> const &items);
    list(const list &l);
    list(list &&l);
    ~list();
    list operator=(list &&l);

    // List Element access
    const_reference front();
    const_reference back();

    // List Capacity
    bool empty();
    size_type size();
    size_type max_size();

    // List Modifiers
    void clear();
    iterator insert(iterator pos, const_reference value);
    void erase(iterator pos);
    void push_back(const_reference value);
    void pop_back();
    void push_front(const_reference value);
    void pop_front();
    void swap(list& other);
    void merge(list& other);
    void splice(const_iterator pos, list& other);
    void reverse();
    void unique();
    void sort();

    
};


}

#endif