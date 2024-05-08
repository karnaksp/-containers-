#ifndef S21_NODE
#define S21_NODE

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
}

#endif