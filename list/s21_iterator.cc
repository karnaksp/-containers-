#include "s21_iterator.h"
#include "s21_node.h"

namespace s21 {
    
    // template <typename T>
    // using value_type = T;
    
    // template <typename T>
    // using reference = value_type&;

    // template <typename T>
    // using const_reference = const value_type&;
    
    // template <typename T>    
    // using iterator = ListIterator<T>;
    
    using size_type = std::size_t;

    template <typename T>
    ListIterator<T>::ListIterator(Node<T>* address) {
        this->current = address;
    }

    template <typename T>
    ListIterator<T>::ListIterator(const ListIterator<T> &other) {
        this->current = other.current;
    }

    template <typename T>
    ListIterator<T>::ListIterator(ListIterator<T> &&other) {
        this->current = other.current;
    }

    template <typename T>
    ListIterator<T>& ListIterator<T>::operator=(const ListIterator<T> &rhs) {
        this->current = rhs.current;
        return *this;
    }

    template <typename T>
    ListIterator<T>& ListIterator<T>::operator=(ListIterator<T> && rhs) {
        this->current = rhs.current;
        return *this;
    }

    template <typename T>
    T& ListIterator<T>::operator*(){
        return this->current->get_value();
    }

    // prefix ++
    template <typename T>
    ListIterator<T>& ListIterator<T>::operator++() {
        if (this->current->get_next() != nullptr) {
            this->current = this->current->get_next();
        } else {
            auto curr = this->current;
            for (; curr->get_prev()->get_prev() != nullptr; curr = curr->get_prev()) {}
            this->current = curr;
        }
        return *this;
    }
    
    // postfix ++
    template <typename T>
    ListIterator<T> ListIterator<T>::operator++(int) {
        ListIterator tmp = ListIterator(this->current);
        if (this->current->get_next() != nullptr) {
            this->current = this->current->get_next();
        } else {
            auto curr = this->current;
            for (; curr->get_prev()->get_prev() != nullptr; curr = curr->get_prev()) {}
            this->current = curr;
        }
        return tmp;
    } 

    // prefix --
    template <typename T>
    ListIterator<T>& ListIterator<T>::operator--() {
        if (this->current->get_prev()->get_prev() != nullptr) {
            this->current = this->current->get_prev();
        } else {
            auto curr = this->current;
            for (; curr->get_next() != nullptr; curr = curr->get_next()) {}
            this->current = curr;
        }
        return *this;
    }  

    // postfix --
    template <typename T>
    ListIterator<T> ListIterator<T>::operator--(int) {
        auto tmp = ListIterator(this->current);
        if (this->current->get_prev()->get_prev() != nullptr) {
            this->current = this->current->get_prev();
        } else {
            auto curr = this->current;
            for (; curr->get_next() != nullptr; curr = curr->get_next()) {}
            this->current = curr;
        }
        return tmp;
    } 

    template <typename T>
    bool ListIterator<T>::operator==(const ListIterator<T> &rhs) {
        return this->current == rhs.current;
    }

    template <typename T>
    bool ListIterator<T>::operator!=(const ListIterator<T> &rhs) {
        return this->current != rhs.current;
    }

}