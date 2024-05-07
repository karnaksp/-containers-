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

         /**********************************
            *
            *   List Helper Functions
            * 
            ***********************************/

void List::print_all_valid_nodes() {
    std::cout << "\n\tSize: " << this->size() << std::endl;
    if (this->empty() == false) {
        int count = 0;
        for (Node* curr = this->head_; curr != nullptr; curr = curr->get_next()) {
            if (curr == post_tail_) {
                break;
            }
            std::cout << "\tList element: " << count << std::endl;
            curr->print_node();
            count++;
        }
    }
}

void List::print_all_nodes_with_hidden() {
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

            /**********************************
            *
            *   List Element access
            * 
            ***********************************/ 


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

 
            /**********************************
            *
            *   List Iterators
            * 
            ***********************************/ 
    iterator List::begin() {
        return iterator::iterator(this->head_);
    }

    iterator List::end() {
        return iterator::iterator(this->post_tail_);
    }

            /**********************************
            *
            *   List Capacity
            * 
            ***********************************/ 


bool List::empty(){
    return (this->size_ == 0) ? true : false;
}


size_type List::size(){
    return this->size_;
}

            /**********************************
            *
            *   List Modifiers
            * 
            ***********************************/ 

void List::clear() {
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


void List::push_back(const_reference value){
    this->post_tail_->insert_node_before_curr(value);
    this->tail_ = this->post_tail_->get_prev();
    if(this->empty() == true) {
        this->head_ = this->tail_;
    }
    this->size_++;
}
    

void List::pop_back(){
    if (this->empty() == false) {
        auto tmp = this->tail_->get_prev();
        this->tail_->delete_current_node();
        this->tail_ = tmp;
        this->size_--;
    }
}
    

void List::push_front(const_reference value){
    this->pre_head_->insert_node_after_curr(value);
    this->head_= this->pre_head_->get_next();
    this->size_++;
}

void List::pop_front(){
    if (this->empty() == false) {
        auto tmp = this->head_->get_next();
        this->head_->delete_current_node();
        this->head_ = tmp;
        this->size_--;
    }
}

}