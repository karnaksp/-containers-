#include <iostream>

#include "s21_list.h"

namespace s21{

Node::Node() 
    :value_ {0},  next_ {nullptr}, prev_ {nullptr}  {
        std::cout << "Node no-param constructor is working" << std::endl;
    }

void Node::insert_node_after(int value){
    std::cout << "insert_node_after is working" << std::endl;
    
    Node* tmp_new = new Node;

    tmp_new->value_ = value;
    
    

    tmp_new->prev_ = this;
    tmp_new->next_ = this->next_;

    if (this->next_ == nullptr) {
        this->next_ = tmp_new;
    } else {
        this->next_->prev_ = tmp_new;
        this->next_ = tmp_new;

    }
}


void Node::delete_current_node(){
    if (prev_ != nullptr) {
        prev_->next_ = next_;
    }

    if (next_ != nullptr) {
        next_->prev_ = prev_;
    }
    delete this;
}


void Node::print_node(){
    std::cout << "\tPrint Node" << std::endl;
    std::cout << "Value: " << value_ << std::endl;
    std::cout << "Curr: " << this << std::endl;
    std::cout << "Prev: " << prev_ << std::endl;
    std::cout << "Next: " << next_ << std::endl;    
}

void Node::delete_all_nodes_curr_and_forward(){
    for (Node* curr = this; curr != nullptr;) {
        Node* tmp = curr->next_;
        delete curr;
        curr = tmp;
    }
}

// template<class T>
// Node::~Node(){
//     delete this;
// }

template<class T>
list<T>::list() {
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