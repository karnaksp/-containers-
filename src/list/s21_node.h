#ifndef S21_NODE
#define S21_NODE

#include <iostream>

namespace s21{

template <typename T>
class Node {
private:
    T value_;
    Node<T>* next_;
    Node<T>* prev_;

public:
    Node();
    
    void insert_node_before_curr(T value);
    void insert_node_after_curr(T value);
    
    void delete_current_node();

    void print_node();
    void print_node_all();
    Node* find_first_node();
    Node* find_last_node();

    // ~Node();

    void delete_all_nodes_curr_and_forward();
    void delete_all_nodes();

    // getters

    T& get_value();
    Node<T>* get_prev();
    Node<T>* get_next();

    // setters

    void set_value(T value);
    void set_prev(Node<T>* new_prev);
    void set_next(Node<T>* new_next);
};


template <typename T>
Node<T>::Node() 
    :value_ {},  next_ {nullptr}, prev_ {nullptr}  {
        // std::cout << "Node no-param constructor is working" << std::endl;
    }

template <typename T>
void Node<T>::insert_node_before_curr(T value){
    // std::cout << "insert_node_before_curr is working" << std::endl;
    
    Node<T>* tmp_new = new Node<T>;

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

template <typename T>
void Node<T>::insert_node_after_curr(T value){
    // std::cout << "insert_node_after_curr is working" << std::endl;

    Node<T>* tmp_new = new Node<T>;

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

template <typename T>
void Node<T>::delete_current_node(){
    if (prev_ != nullptr) {
        prev_->next_ = next_;
    }

    if (next_ != nullptr) {
        next_->prev_ = prev_;
    }
    delete this;
}

template <typename T>
void Node<T>::print_node(){
    std::cout << "\tPrint Node" << std::endl;
    std::cout << "Value: " << value_ << std::endl;
    std::cout << "Curr: " << this << std::endl;
    std::cout << "Prev: " << prev_ << std::endl;
    std::cout << "Next: " << next_ << std::endl;    
}

template <typename T>
void Node<T>::print_node_all(){
    Node<T>* first_element = this->find_first_node();

    int i = 0;
    for (Node<T>* curr = first_element; curr != nullptr; curr = curr->next_) {
        std::cout << "\nNode number " << i << std::endl;
        curr->print_node();
        i++;
    }
}

template <typename T>
Node<T>* Node<T>::find_first_node(){
    Node* curr = this;
    for (; curr != nullptr; curr = curr->prev_){
        if (curr->prev_ == nullptr) {
            break;
        }
    }
    return curr;
}

template <typename T>
Node<T>* Node<T>::find_last_node(){
    Node<T>* curr = this;
    for (; curr != nullptr; curr = curr->next_){
        if (curr->next_ == nullptr) {
            break;
        }
    }
    return curr;
}

template <typename T>
void Node<T>::delete_all_nodes_curr_and_forward(){
    for (Node<T>* curr = this; curr != nullptr;) {
        Node<T>* tmp = curr->next_;
        delete curr;
        curr = tmp;
    }
}

template <typename T>
void Node<T>::delete_all_nodes(){
    Node<T> * first_element = this->find_first_node();
    first_element->delete_all_nodes_curr_and_forward();
}


// template<class T>
// Node::~Node(){
//     delete this;
// }


    // getters
    template <typename T>
    T& Node<T>::get_value() {
        return this->value_;
    }

    template <typename T>
    Node<T>* Node<T>::get_prev() {
        return this->prev_;
    }

    template <typename T>
    Node<T>* Node<T>::get_next(){
        return this->next_;
    }

    // setters

    template <typename T>
    void Node<T>::set_value(T value) {
        this->value_ = value;
    }

    template <typename T>
    void Node<T>::set_prev(Node<T>* new_prev) {
        this->prev_ = new_prev;
    }

    template <typename T>
    void Node<T>::set_next(Node<T>* new_next) {
        this->next_ = new_next;
    }

}

#endif