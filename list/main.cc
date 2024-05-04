#include <iostream>

#include "s21_list.h"

int main() {

    s21::Node* new_node = new s21::Node;
    new_node->insert_node_after(2);

    new_node->print_node();
    new_node->next_->print_node();

    // new_node->next_->delete_current_node();
    // new_node->print_node();

    new_node->delete_all_nodes_curr_and_forward();
    // new_node->print_node();


    return 0;
}