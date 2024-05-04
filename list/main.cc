#include <iostream>

#include "s21_list.h"

int main() {

    s21::Node<int>* new_node = new s21::Node<int>;
    new_node->insert_node_after(2);

    new_node->print_node();
    return 0;
}