#include <iostream>

#include "s21_list.h"
#include "s21_node.h"
#include "s21_iterator.h"

namespace s21{


list::list() {
    std::cout << "No-args List constructor is working" << std::endl;

    pre_head_ = new Node;
    pre_head_->prev_ = nullptr;

    post_tail_ = new Node;
    post_tail_->next_ = nullptr;

    pre_head_->next_ = post_tail_;
    post_tail_->prev_ = pre_head_;

    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}



}