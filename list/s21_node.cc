#include <iostream>

#include "s21_node.h"


namespace s21{

Node::Node() 
    :value_ {0},  next_ {nullptr}, prev_ {nullptr}  {
        std::cout << "Node no-param constructor is working" << std::endl;
    }

void Node::insert_node_before_curr(int value){
    std::cout << "insert_node_before_curr is working" << std::endl;
    
    Node* tmp_new = new Node;

    tmp_new->value_ = value;
    
    tmp_new->prev_ = this->prev_;
    tmp_new->next_ = this;

    if (this->prev_ == nullptr) {
        this->prev_ = tmp_new;
    } else {
        this->prev_->next_ = tmp_new;
        this->prev_ = tmp_new;

    }
}

void Node::insert_node_after_curr(int value){
    std::cout << "insert_node_after_curr is working" << std::endl;
    
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

void Node::print_node_all(){
    Node * first_element = this->find_first_node();

    int i = 0;
    for (Node* curr = first_element; curr != nullptr; curr = curr->next_) {
        std::cout << "\nNode number " << i << std::endl;
        curr->print_node();
        i++;
    }
}

Node* Node::find_first_node(){
    Node* curr = this;
    for (; curr != nullptr; curr = curr->prev_){
        if (curr->prev_ == nullptr) {
            break;
        }
    }
    return curr;
}

Node* Node::find_last_node(){
    Node* curr = this;
    for (; curr != nullptr; curr = curr->next_){
        if (curr->next_ == nullptr) {
            break;
        }
    }
    return curr;
}

void Node::delete_all_nodes_curr_and_forward(){
    for (Node* curr = this; curr != nullptr;) {
        Node* tmp = curr->next_;
        delete curr;
        curr = tmp;
    }
}

void Node::delete_all_nodes(){
    Node * first_element = this->find_first_node();
    first_element->delete_all_nodes_curr_and_forward();
}


// template<class T>
// Node::~Node(){
//     delete this;
// }


    // getters

    int& Node::get_value() {
        return this->value_;
    }
    Node* Node::get_prev() {
        return this->prev_;
    }
    Node* Node::get_next(){
        return this->next_;
    }

    // setters

    void Node::set_value(int value) {
        this->value_ = value;
    }
    void Node::set_prev(Node* new_prev) {
        this->prev_ = new_prev;
    }
    void Node::set_next(Node* new_next) {
        this->next_ = new_next;
    }

}