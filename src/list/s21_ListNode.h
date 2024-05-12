#ifndef S21_ListNode_H
#define S21_ListNode_H

#include <iostream>

namespace s21{

template <typename T>
class ListNode {
private:
    T value_;
    ListNode<T>* next_;
    ListNode<T>* prev_;

public:
    ListNode();
    
    void insert_ListNode_before_curr(T value);
    void insert_ListNode_after_curr(T value);
    
    void delete_current_ListNode();

    void print_ListNode();
    void print_ListNode_all();
    ListNode* find_first_ListNode();
    ListNode* find_last_ListNode();

    // ~ListNode();

    void delete_all_ListNodes_curr_and_forward();
    void delete_all_ListNodes();

    // getters

    T& get_value();
    ListNode<T>* get_prev();
    ListNode<T>* get_next();

    // setters

    void set_value(T value);
    void set_prev(ListNode<T>* new_prev);
    void set_next(ListNode<T>* new_next);

    // comparison

    bool operator==(const ListNode<T> &rhs);
    bool operator<(const ListNode<T> &rhs);

    // swap

    void swap(ListNode<T>& other);
};


template <typename T>
ListNode<T>::ListNode() 
    :value_ {},  next_ {nullptr}, prev_ {nullptr}  {
        // std::cout << "ListNode no-param constructor is working" << std::endl;
    }

template <typename T>
void ListNode<T>::insert_ListNode_before_curr(T value){
    // std::cout << "insert_ListNode_before_curr is working" << std::endl;
    
    ListNode<T>* tmp_new = new ListNode<T>;

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
void ListNode<T>::insert_ListNode_after_curr(T value){
    // std::cout << "insert_ListNode_after_curr is working" << std::endl;

    ListNode<T>* tmp_new = new ListNode<T>;

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
void ListNode<T>::delete_current_ListNode(){
    if (prev_ != nullptr) {
        prev_->next_ = next_;
    }

    if (next_ != nullptr) {
        next_->prev_ = prev_;
    }
    delete this;
}

template <typename T>
void ListNode<T>::print_ListNode(){
    std::cout << "\tPrint ListNode" << std::endl;
    std::cout << "Value: " << value_ << std::endl;
    std::cout << "Curr: " << this << std::endl;
    std::cout << "Prev: " << prev_ << std::endl;
    std::cout << "Next: " << next_ << std::endl;    
}

template <typename T>
void ListNode<T>::print_ListNode_all(){
    ListNode<T>* first_element = this->find_first_ListNode();

    int i = 0;
    for (ListNode<T>* curr = first_element; curr != nullptr; curr = curr->next_) {
        std::cout << "\nListNode number " << i << std::endl;
        curr->print_ListNode();
        i++;
    }
}

template <typename T>
ListNode<T>* ListNode<T>::find_first_ListNode(){
    ListNode* curr = this;
    for (; curr != nullptr; curr = curr->prev_){
        if (curr->prev_ == nullptr) {
            break;
        }
    }
    return curr;
}

template <typename T>
ListNode<T>* ListNode<T>::find_last_ListNode(){
    ListNode<T>* curr = this;
    for (; curr != nullptr; curr = curr->next_){
        if (curr->next_ == nullptr) {
            break;
        }
    }
    return curr;
}

template <typename T>
void ListNode<T>::delete_all_ListNodes_curr_and_forward(){
    for (ListNode<T>* curr = this; curr != nullptr;) {
        ListNode<T>* tmp = curr->next_;
        delete curr;
        curr = tmp;
    }
}

template <typename T>
void ListNode<T>::delete_all_ListNodes(){
    ListNode<T> * first_element = this->find_first_ListNode();
    first_element->delete_all_ListNodes_curr_and_forward();
}


// template<class T>
// ListNode::~ListNode(){
//     delete this;
// }


    // getters
    template <typename T>
    T& ListNode<T>::get_value() {
        return this->value_;
    }

    template <typename T>
    ListNode<T>* ListNode<T>::get_prev() {
        return this->prev_;
    }

    template <typename T>
    ListNode<T>* ListNode<T>::get_next(){
        return this->next_;
    }

    // setters

    template <typename T>
    void ListNode<T>::set_value(T value) {
        this->value_ = value;
    }

    template <typename T>
    void ListNode<T>::set_prev(ListNode<T>* new_prev) {
        this->prev_ = new_prev;
    }

    template <typename T>
    void ListNode<T>::set_next(ListNode<T>* new_next) {
        this->next_ = new_next;
    }

    template <typename T>
    bool ListNode<T>::operator==(const ListNode<T> &rhs) {
        return this->value_ == rhs.value_;
    }

    template <typename T>
    bool ListNode<T>::operator<(const ListNode<T> &rhs){
        return this->value_ < rhs.value_;
    }

    template <typename T>
    void ListNode<T>::swap(ListNode<T>& other){
        auto prev_of_this = this->prev_;
        auto next_of_this = this->next_;

        auto prev_of_other = other.prev_;
        auto next_of_other = other.next_;
        


        if (this->prev_ == &other) {
            other.prev_->next_ = this;
            this->next_->prev_ = &other;

            this->prev_ = prev_of_other;
            this->next_ = &other;

            other.prev_ = this;
            other.next_ = next_of_this;
        } else if (this->next_ == &other) {
            this->prev_->next_ = &other;
            other.next_->prev_ = this;

            other.prev_ = prev_of_this;
            other.next_ = this;

            this->prev_ = &other;
            this->next_ = next_of_other;
        } else {
        
        this->next_->prev_ = &other;
        this->prev_->next_ = &other;
        
        other.prev_->next_ = this;
        other.next_->prev_ = this;
        
        auto tmp_prev_ = this->prev_;
        auto tmp_next = this->next_;

        this->prev_ = other.prev_;
        this->next_ = other.next_;

        other.prev_ = tmp_prev_;
        other.next_ = tmp_next;
    }
    }


}

#endif