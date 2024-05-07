#include "s21_iterator.h"
#include "s21_node.h"

namespace s21 {
    using value_type = int;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = ListIterator;
    using size_type = std::size_t;

    ListIterator::ListIterator(Node* address) {
        this->current = address;
    }

    ListIterator::ListIterator(const ListIterator &other) {
        this->current = other.current;
    }

    ListIterator::ListIterator(ListIterator &&other) {
        this->current = other.current;
    }

    ListIterator& ListIterator::operator=(const ListIterator &rhs) {
        this->current = rhs.current;
        return *this;
    }

    ListIterator& ListIterator::operator=(ListIterator && rhs) {
        this->current = rhs.current;
        return *this;
    }

    value_type& ListIterator::operator*(){
        return this->current->get_value();
    }

    // prefix ++
    ListIterator& ListIterator::operator++() {
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
    ListIterator ListIterator::operator++(int) {
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
    ListIterator& ListIterator::operator--() {
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
    ListIterator ListIterator::operator--(int) {
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

    bool ListIterator::operator==(const ListIterator &rhs) {
        return this->current == rhs.current;
    }

    bool ListIterator::operator!=(const ListIterator &rhs) {
        return this->current != rhs.current;
    }











}