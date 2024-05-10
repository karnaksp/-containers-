#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include <cstddef>
#include <initializer_list>
#include <limits>

#include "../list/s21_list.h"
#include "../list/s21_node.h"
#include "../list/s21_iterator.h"

namespace s21 {

using size_type = std::size_t;

template<typename T>
class Queue{
private:
    List<T> queue_;

public:
           /**********************************
            *
            *   Queue Helper Functions
            * 
            ***********************************/
    void print_all();


            /**********************************
            *
            *   Queue Member functions
            * 
            ***********************************/ 

    // default constructor, creates an empty queue
    Queue();

    // initializer list constructor, creates queue 
    // initizialized using std::initializer_list
    Queue(std::initializer_list<T> const &items);

    // copy constructor
    Queue(const Queue<T> &q);

    // move constructor
    Queue(Queue &&q);

    // destructor
    ~Queue();

    // assignment operator overload for moving an object
   Queue<T>  operator=(Queue &&q);



            /**********************************
            *
            *   Queue Element access
            * 
            ***********************************/ 
    // access the first element
    const T& front();

    // access the last element
    const T& back();

            /**********************************
            *
            *   Queue Capacity
            * 
            ***********************************/ 

    // checks whether the container is empty
    bool empty();

    // returns the number of elements
    size_type size();
    
            /**********************************
            *
            *   Queue Modifiers
            * 
            ***********************************/ 

    // inserts an element at the end
    void push(const T& value);

    // removes the first element
    void pop();

    // swaps the contents
    void swap(Queue& other);

};


          
          
            /**********************************
            *
            *   Queue Helper Functions
            * 
            ***********************************/
    
    template <typename T>
    void Queue<T>::print_all() {
        queue_.print_all_valid_nodes();
    }


            /**********************************
            *
            *   Queue Member functions
            * 
            ***********************************/ 

    // default constructor, creates an empty queue
    template <typename T>
    Queue<T>::Queue() {
    }

    // initializer list constructor, creates queue 
    // initizialized using std::initializer_list
    template <typename T>
    Queue<T>::Queue(std::initializer_list<T> const &items) {
        for (auto it = items.begin(); it != items.end(); it++) {
            this->queue_.push_back(*it);
        }
    }

    // copy constructor
    template <typename T>
    Queue<T>::Queue(const Queue<T> &q){
        this->queue_ = q.queue_;
    }

    // move constructor
    template <typename T>
    Queue<T>::Queue(Queue &&q){
        this->queue_ = q.queue_;
    }

    // destructor
    template <typename T>
    Queue<T>::~Queue(){

    }

    // assignment operator overload for moving an object
   template <typename T>
   Queue<T>  Queue<T>::operator=(Queue &&q){
        this->queue_ = q.queue_;
   }



            /**********************************
            *
            *   Queue Element access
            * 
            ***********************************/ 
    // access the first element
    template <typename T>
    const T& Queue<T>::front(){
        return this->queue_.front();
    }

    // access the last element
    template <typename T>
    const T& Queue<T>::back(){
        return this->queue_.back();
    }

            /**********************************
            *
            *   Queue Capacity
            * 
            ***********************************/ 

    // checks whether the container is empty
    template <typename T>
    bool Queue<T>::empty(){
        return queue_.empty();
    }

    // returns the number of elements
    template <typename T>
    size_type Queue<T>::size(){
        return queue_.size();
    }
    
            /**********************************
            *
            *   Queue Modifiers
            * 
            ***********************************/ 

    // inserts an element at the end
    template <typename T>
    void Queue<T>::push(const T& value){
        this->queue_.push_back(value);
    }

    // removes the first element
    template <typename T>
    void Queue<T>::pop(){
        this->queue_.pop_front();
    }

    // swaps the contents
    template <typename T>
    void Queue<T>::swap(Queue& other){
        auto tmp = this->queue_;
        this->queue_ = other.queue_;
        other.queue_ = tmp;
    }
























}

#endif