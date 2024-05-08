#include <iostream>

#include <initializer_list>

#include "s21_list.h"
#include "s21_node.h"
#include "s21_iterator.h"

namespace s21{

    // using value_type = int;
    // using reference = value_type&;
    // using const_reference = const value_type&;
    // using iterator = ListIterator;
    // using const_iterator = ListConstIterator;
    using size_type = std::size_t;

         /**********************************
            *
            *   List Helper Functions
            * 
            ***********************************/

template <typename T>
void List<T>::print_all_valid_nodes() {
    std::cout << "\n\tSize: " << this->size() << std::endl;
    if (this->empty() == false) {
        int count = 0;
        for (Node<T>* curr = this->head_; curr != nullptr; curr = curr->get_next()) {
            if (curr == post_tail_) {
                break;
            }
            std::cout << "\tList element: " << count << std::endl;
            curr->print_node();
            count++;
        }
    }
}

template <typename T>
void List<T>::print_all_nodes_with_hidden() {
    std::cout << "\n\tpre_head_: " << std::endl;
    this->pre_head_->print_node();
    this->print_all_valid_nodes();
    std::cout << "\n\tpost_tail_: " << this->post_tail_ << std::endl;
    this->post_tail_->print_node();
}

            /**********************************
            *
            *   List Functions
            * 
            ***********************************/ 

template <typename T>
List<T>::List() {
    std::cout << "No-args List constructor is working" << std::endl;
    
    size_ = 0;
    head_ = nullptr;
    tail_ = nullptr;

    pre_head_ = new Node<T>;
    pre_head_->set_prev(nullptr);

    post_tail_ = new Node<T>;
    post_tail_->set_next(nullptr);

    pre_head_->set_next(post_tail_);
    post_tail_->set_prev(pre_head_);
}

template <typename T>
List<T>::List(size_type n) : List()  {
    for (size_type i = 0; i < n; i++) {
        this->push_back(0);
    }
}

template <typename T>
List<T>::List(std::initializer_list<T> const &items)
    : List() {
        for (auto it = items.begin(); it != items.end(); it++) {
            this->push_back(*it);
        }
}

template <typename T>
List<T>::List(const List<T> &l) : List(){
    if (l.size_ != 0) {
        for (auto it = l.head_; it != l.post_tail_; it = it->get_next()) {
            this->push_back(it->get_value());
        }
    }
}

template <typename T>
List<T>::List(List<T> &&l) : List() {
    this->head_ = l.head_;
    this->tail_ = l.tail_;
    this->pre_head_ = l.pre_head_;
    this->post_tail_ = l.post_tail_;
    this->size_ = l.size_;
    l.head_ = nullptr;
    l.tail_ = nullptr;
    l.pre_head_ = nullptr;
    l.post_tail_ = nullptr;
    l.size_ = 0;
}

template <typename T>
List<T>::~List(){
    std::cout << "List destructor is working" << std::endl;
    this->pre_head_->delete_all_nodes();
}

            /**********************************
            *
            *   List Element access
            * 
            ***********************************/ 

template <typename T>
const T& List<T>::front() {
    if (size_ != 0) {
        return head_->get_value();
    } else {
        return pre_head_->get_value();
    }
}

template <typename T>
const T& List<T>::back() {
    if (size_ != 0) {
        return tail_->get_value();
    } else {
        return pre_head_->get_value();
    }
}

 
            /**********************************
            *
            *   List Iterators
            * 
            ***********************************/ 
    template <typename T>
    ListIterator<T> List<T>::begin() {
        return ListIterator<T>::iterator(this->head_);
    }

    template <typename T>
    ListIterator<T> List<T>::end() {
        return ListIterator<T>::iterator(this->post_tail_);
    }

            /**********************************
            *
            *   List Capacity
            * 
            ***********************************/ 

template <typename T>
bool List<T>::empty(){
    return (this->size_ == 0) ? true : false;
}

template <typename T>
size_type List<T>::size(){
    return this->size_;
}

            /**********************************
            *
            *   List Modifiers
            * 
            ***********************************/ 

template <typename T>
void List<T>::clear() {
     auto curr = this->head_;
     for(; curr != nullptr;) {
        if (curr == post_tail_) {
            break;
        }
        auto tmp = curr->get_next();
        curr->delete_current_node();
        curr = tmp;
     }
     this->size_ = 0;
}

template <typename T>
void List<T>::push_back(const T& value){
    this->post_tail_->insert_node_before_curr(value);
    this->tail_ = this->post_tail_->get_prev();
    if(this->empty() == true) {
        this->head_ = this->tail_;
    }
    this->size_++;
}
    
template <typename T>
void List<T>::pop_back(){
    if (this->empty() == false) {
        auto tmp = this->tail_->get_prev();
        this->tail_->delete_current_node();
        this->tail_ = tmp;
        this->size_--;
    }
}
    
template <typename T>
void List<T>::push_front(const T& value){
    this->pre_head_->insert_node_after_curr(value);
    this->head_= this->pre_head_->get_next();
    this->size_++;
}

template <typename T>
void List<T>::pop_front(){
    if (this->empty() == false) {
        auto tmp = this->head_->get_next();
        this->head_->delete_current_node();
        this->head_ = tmp;
        this->size_--;
    }
}

}