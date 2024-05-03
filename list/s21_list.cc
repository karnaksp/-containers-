#include <iostream>

#include "s21_list.h"

namespace s21{
    
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