#include <iostream>

#include "s21_list.h"

int main() {

    /*
    *   insert_node_after_curr
    */

    // s21::Node* new_node = new s21::Node;
    // new_node->insert_node_after_curr(2);

    // new_node->print_node();
    // new_node->next_->print_node();

    // // new_node->next_->delete_current_node();
    // // new_node->print_node();

    // new_node->delete_all_nodes_curr_and_forward();
    // // new_node->print_node();


    /*
    *   insert_node_before_curr
    */

   s21::Node* new_ptr = new s21::Node;
   new_ptr->insert_node_before_curr(12);

   new_ptr->print_node_all();
   
   new_ptr->prev_->delete_all_nodes_curr_and_forward();




    return 0;
}