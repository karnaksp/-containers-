#ifndef S21_NODE
#define S21_NODE

namespace s21{
    class Node {
public:
    int value_;
    Node* next_;
    Node* prev_;

public:
    Node();
    
    void insert_node_before_curr(int value);
    void insert_node_after_curr(int value);
    
    void delete_current_node();

    void print_node();
    void print_node_all();
    Node* find_first_node();
    Node* find_last_node();

    // ~Node();

    void delete_all_nodes_curr_and_forward();
    void delete_all_nodes();
};
}

#endif