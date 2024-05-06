#include <iostream>

#include "s21_list.h"
#include "s21_node.h"
#include "s21_iterator.h"

namespace s21{

    using value_type = int;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = ListIterator;
    using const_iterator = ListConstIterator;
    using size_type = std::size_t;


List::List() {
    std::cout << "No-args List constructor is working" << std::endl;
    
    size_ = 0;
    head_ = nullptr;
    tail_ = nullptr;

    pre_head_ = new Node;
    pre_head_->set_prev(nullptr);

    post_tail_ = new Node;
    post_tail_->set_next(nullptr);

    pre_head_->set_next(post_tail_);
    post_tail_->set_prev(pre_head_);

}

List::~List(){
    std::cout << "List destructor is working" << std::endl;
    this->pre_head_->delete_all_nodes();
}

const_reference List::front() {
    if (size_ != 0) {
        return head_->get_value();
    } else {
        return pre_head_->get_value();
    }
}

const_reference List::back() {
    if (size_ != 0) {
        return tail_->get_value();
    } else {
        return pre_head_->get_value();
    }
}

    bool List::empty(){
        return (this->size_ == 0) ? true : false;
    }


    size_type List::size(){
        return this->size_;
    }

void List::push_back(const_reference value){
    this->post_tail_->insert_node_before_curr(value);
    this->tail_ = this->post_tail_->get_prev();
    this->size_++;
}
    

void List::pop_back(){
    this->tail_ = this->tail_->get_prev();
    this->tail_->delete_current_node();
    this->size_--;
}
    

void List::push_front(const_reference value){
    this->pre_head_->insert_node_after_curr(value);
    this->head_= this->pre_head_->get_next();
    this->size_++;
}

void List::pop_front(){
    this->head_ = this->head_->get_next();
    this->head_->delete_current_node();
    this->size_--;
}

}