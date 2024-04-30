#ifndef S21_LIST
#define S21_LIST

namespace s21 {

template<class T>
class list {
private:
    list* next;
    list* previous;
    T value;

public:
    // List Functions
    list();
    list(std::size_type n);
    list(std::initializer_list<T> const &items);
    list(const list &l);
    list(list &&l);
    ~list();
    operator=(list &&l);

    // List Element access
    const T& front();
    const T& back();

    
};


}

#endif