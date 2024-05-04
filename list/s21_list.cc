#include <iostream>

#include "s21_list.h"

namespace s21{

template<class T>
void Node<T>::insert_node_after(T value){
    Node<T>* tmp_new = new Node<T>;
    tmp_new->value_ = value;
    
    tmp_new->prev_ = this;
    tmp_new->next_ = this->next_;

    this->next_->prev_ = tmp_new;
    this->next_ = tmp_new;
}

template<class T>
void Node<T>::delete_current_node(){
    prev_->next_ = next_;
    next_->prev_ = prev_;
    delete this;
}

template<class T>
void Node<T>::print_node(){
    std::cout << "Print Node" << std::endl;
    std::cout << "Value: " << value_ << std::endl;
    std::cout << "Prev: " << prev_ << std::endl;
    std::cout << "Next: " << next_ << std::endl;
    
}

// template<class T>
// Node<T>::~Node(){
//     delete this;
// }

template<class T>
list<T>::list() {
    std::cout << "No-args List constructor is working" << std::endl;

    pre_head_ = new Node<T>;
    pre_head_->prev = nullptr;

    post_tail_ = new Node<T>;
    post_tail_->next = nullptr;

    pre_head_->next = post_tail_;
    post_tail_->prev = pre_head_;

    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}



}