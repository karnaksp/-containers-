#ifndef S21_LIST_H
#define S21_LIST_H

#include <cstddef>
#include <initializer_list>
#include <limits>

#include "s21_iterator.h"
#include "s21_node.h"

namespace s21 {

using size_type = std::size_t;

template <typename T>
class List {
public:

    using size_type = std::size_t;
private:
    Node<T>* head_;
    Node<T>* tail_;
    Node<T>* pre_head_;
    Node<T>* post_tail_;
    size_type size_;

public:    
         /**********************************
            *
            *   List Helper Functions
            * 
            ***********************************/
    
//     friend void Node::insert_node_before_curr(int value);
    
//     friend void Node::delete_current_node();

    void print_all_valid_nodes();
    void print_all_nodes_with_hidden();

            /**********************************
            *
            *   List Functions
            * 
            ***********************************/ 

    // default constructor, creates an empty list
    List();

    // parameterized constructor, creates the list of size n
    List(size_type n);

    /*
    initializer list constructor, 
    creates a list initizialized using std::initializer_list
    */
    List(std::initializer_list<T> const &items);

    // copy constructor
    List(const List<T> &l);

    // move constructor
    List(List<T> &&l);

    // destructor
    ~List();

    // assignment operator overload for moving an object
    List<T> operator=(List<T> &&l);

            /**********************************
            *
            *   List Element access
            * 
            ***********************************/ 

    // access the first element
    const T& front();

    // access the last element
    const T& back();
 
            /**********************************
            *
            *   List Iterators
            * 
            ***********************************/ 

    // returns an iterator to the beginning
    ListIterator<T> begin();

    ListConstIterator<T> cbegin();

    // returns an iterator to the end
    ListIterator<T> end(); 
 
            /**********************************
            *
            *   List Capacity
            * 
            ***********************************/ 

    // checks whether the container is empty
    bool empty();

    // returns the number of elements
    size_type size();

    // returns the maximum possible number of elements
    size_type max_size();
          
            /**********************************
            *
            *   List Modifiers
            * 
            ***********************************/ 
    
    // clears the contents
    void clear();
    
    /*
    inserts element into concrete pos and 
    returns the iterator that points to the new element
    */
    ListIterator<T> insert(ListIterator<T> pos, const T& value);
    void insert(ListConstIterator<T> pos, const T& value);
    
    // erases an element at pos
    void erase(ListIterator<T> pos);
    
    // adds an element to the end
    void push_back(const T& value);
    
    // removes the last element
    void pop_back();
    
    // adds an element to the head
    void push_front(const T& value);
    
    // removes the first element
    void pop_front();
    
    // swaps the contents
    void swap(List<T>& other);
    
    // merges two sorted lists
    void merge(List<T>& other);
    
    // transfers elements from list other starting from pos
    void splice(ListIterator<T> pos, List<T>& other);
    
    // reverses the order of the elements
    void reverse();
    
    // removes consecutive duplicate elements
    void unique();
    
    // sorts the elements
    void sort();
};



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
//     std::cout << "No-args List constructor is working" << std::endl;
    
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

template <typename T>
List<T> List<T>::operator=(List<T> &&l) {
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

    return *this;
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
        return typename s21::ListIterator<T>::ListIterator(this->head_);
    }

    template <typename T>
    ListConstIterator<T> List<T>::cbegin() {
        return typename s21::ListConstIterator<T>::ListConstIterator(this->head_);
    }

    template <typename T>
    ListIterator<T> List<T>::end() {
        return typename s21::ListIterator<T>::ListIterator(this->post_tail_);
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

template <typename T>
size_type List<T>::max_size() {
        auto minus_list = std::numeric_limits<std::size_t>::max() - sizeof(List<T>);
        return  minus_list /  sizeof(Node<T>) ;
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
ListIterator<T> List<T>::insert(ListIterator<T> pos, const T& value){
        auto pos_tmp = pos;
        auto ref = pos.current;
        ref->insert_node_before_curr(value);
        this->size_++;
        if (ref == this->head_) {
                this->head_ = this->head_->get_prev();
        }
        return ListIterator(pos.current->get_next());
}

template <typename T>
void List<T>::insert(ListConstIterator<T> pos, const T& value){
        auto pos_tmp = pos;
        auto ref = pos.current;
        ref->insert_node_before_curr(value);
        this->size_++;
        if (ref == this->head_) {
                this->head_ = this->head_->get_prev();
        }
}

template <typename T>
void List<T>::erase(ListIterator<T> pos){
        auto pos_tmp = pos;
        auto ref = pos.current;
        auto tmp = this->head_->get_next();
        ref->delete_current_node();
        if (ref == this->head_) {
                this->head_ = tmp;
        }
        this->size_--;
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


// swaps the contents
template <typename T>
void List<T>::swap(List<T>& other){
        auto tmp_head_ = this->head_;
        auto tmp_tail_ = this->tail_;
        auto tmp_pre_head_ = this->pre_head_;
        auto tmp_post_tail_ = this->post_tail_;
        auto tmp_size_ = this->size_;

        this->head_ = other.head_;
        this->tail_ = other.tail_;
        this->pre_head_ = other.pre_head_;
        this->post_tail_ = other.post_tail_;
        this->size_ = other.size_;

        other.head_ = tmp_head_;
        other.tail_ = tmp_tail_;
        other.pre_head_ = tmp_pre_head_;
        other.post_tail_ = tmp_post_tail_;
        other.size_ = tmp_size_;
}
    
// merges two sorted lists
template <typename T>
void List<T>::merge(List<T>& other){
    for (auto i = this->begin(); i != this->end(); i++) {
        for (auto j = other.begin(); j != other.end(); ) {
            if (*j < *i || *j == *i) {
                if (i == this->begin()) {
                    this->push_front(*j);
                    
                } else {
                    auto tmp = i;
                    this->insert(tmp, *j);
                }
                auto tmp = j;
                tmp++;
                other.erase(j);
                j = tmp;
                
            }
            else {
                break;
            }
        }
    }
}
    
// transfers elements from list other starting from pos
template <typename T>
void List<T>::splice(ListIterator<T> pos, List<T>& other){
    auto tmp_pos = pos.current;
    auto just_it = ListIterator<T>(tmp_pos);
    for (auto it = other.begin(); it != other.end();) {
        if (tmp_pos == this->begin().current) {
            this->push_front(*it);
                    
        } else {
            this->insert(pos, *it);
        }
        auto tmp = it;
        tmp++;
        other.erase(it);
        it = tmp;

    }
}
    
// reverses the order of the elements
template <typename T>
void List<T>::reverse(){
    auto tmp_it_front = this->begin();
    // auto tmp_pre_head = tmp_it_front.current->get_prev();
    auto tmp_it_back = this->end();
    auto tmp_it_back_back = tmp_it_back;
    tmp_it_back_back--;


    for (auto it = this->begin(); it != tmp_it_back;) {
        auto it_next = it;
        it_next++;
        if (it == this->begin()) {
            it.current->set_prev(it.current->get_next());
            it.current->set_next( tmp_it_back.current);
            this->tail_ = it.current;
        } else if (it == tmp_it_back_back) {
            it.current->set_next(it.current->get_prev());
            it.current->set_prev( it.current->get_next());
            this->head_ = it.current;
        } else {
            auto tmp_next = it.current->get_next();
            it.current->set_next(it.current->get_prev());
            it.current->set_prev( tmp_next);
        }

        it = it_next;
    }


}
    
// removes consecutive duplicate elements
template <typename T>
void List<T>::unique(){
    for (auto it = this->begin(); it != this->end();) {
        auto next_it = it;
        next_it++;
        if (*it == *next_it) {
            this->erase(it);
        }
        it = next_it;

    }
}
    
// sorts the elements
template <typename T>
void List<T>::sort(){

    for (auto i = this->begin(); i != this->end(); i++) {
        auto min = i;

        for (auto j = i; j != this->end(); j++ ) {
            if (i == j) {
                continue;
            }

            if (*min > *j) {
                min = j;      
            }
        }
        if (min != i) {            
            auto tmp = min.current;
            i.current->swap(*tmp);

            if (i == this->begin()) {
                this->head_ = min.current;
            }
            i = min;
        }
    }
}


}

#endif