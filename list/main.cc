#include <iostream>

#include "s21_list.h"
#include "s21_node.h"

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


/*
*
*   Test of inserts, print all and delete all
*  
*/
//    s21::Node* new_ptr = new s21::Node;
//    new_ptr->insert_node_before_curr(12);
//    new_ptr->insert_node_after_curr(16);
//    new_ptr->insert_node_after_curr(17);
//    new_ptr->insert_node_after_curr(18);
//    new_ptr->print_node_all();
//    new_ptr->delete_all_nodes();
   
/*
*
*   List push and pop, clear and prints
*
*/

// s21::List list;
// list.push_back(1);
// list.push_back(2);
// list.push_back(3);
// list.push_back(4);
// list.push_front(-10);
// list.print_all_valid_nodes();
// std::cout << "\nSize: " << list.size() << std::endl;
// list.pop_front();
// list.print_all_valid_nodes();
// list.pop_back();
// list.print_all_valid_nodes();
// std::cout << "\nSize: " << list.size() << std::endl;
// list.pop_back();
// list.pop_back();
// list.pop_back();
// list.pop_back();
// std::cout << "\nSize: " << list.size() << std::endl;
// list.push_front(101);
// list.push_back(999);
// list.print_all_nodes_with_hidden();
// std::cout << "\nlist.clear() "  << std::endl;
// list.clear();
// list.print_all_nodes_with_hidden();


/*
*
*   List iterators
*
*/

// s21::List list;
// list.push_back(1);
// list.push_back(2);
// list.push_back(3);
// list.push_back(4);
// list.push_front(-10);

// list.print_all_valid_nodes();

// auto start = list.begin();
// std::cout << "Start: " << *start << std::endl;

// auto finish = list.back();
// std::cout << "Finish: " << finish << std::endl;


/*
*
*   List iterators post++
*
*/

// std::cout << "++: " << *start << std::endl;
// start++;
// std::cout << "++: " << *start << std::endl;
// start++;
// std::cout << "++: " << *start << std::endl;
// start++;
// std::cout << "++: " << *start << std::endl;
// start++;
// std::cout << "++: " << *start << std::endl;
// start++;
// std::cout << "++: " << *start << std::endl;
// start++;
// std::cout << "++: " << *start << std::endl;
// start++;
// std::cout << "++: " << *start << std::endl;
// start++;
// std::cout << "++: " << *start << std::endl;
// start++;
// std::cout << "++: " << *start << std::endl;
// start++;
// std::cout << "++: " << *start << std::endl;
// start++;
// std::cout << "++: " << *start << std::endl;
// start++;
// std::cout << "++: " << *start << std::endl;

/*
*
*   List iterators pre++
*
*/

// std::cout << "++: " << *start << std::endl;
// ++start;
// std::cout << "++: " << *start << std::endl;
// ++start;
// std::cout << "++: " << *start << std::endl;
// ++start;
// std::cout << "++: " << *start << std::endl;
// ++start;
// std::cout << "++: " << *start << std::endl;
// ++start;
// std::cout << "++: " << *start << std::endl;
// ++start;
// std::cout << "++: " << *start << std::endl;
// ++start;
// std::cout << "++: " << *start << std::endl;
// ++start;
// std::cout << "++: " << *start << std::endl;
// ++start;
// std::cout << "++: " << *start << std::endl;
// ++start;
// std::cout << "++: " << *start << std::endl;
// ++start;
// std::cout << "++: " << *start << std::endl;


/*
*
*   List iterators loop
*
*/

// for (auto it = list.begin(); it != list.end(); it++) {
//     std::cout << *it << std::endl;
//     *it = 12;
//     std::cout << *it << std::endl;
// }

// list.print_all_valid_nodes();

/*
*
*   List iterators pre--
*
*/

// --start;
// std::cout << "++: " << *start << std::endl;
// --start;
// std::cout << "++: " << *start << std::endl;
// --start;
// std::cout << "++: " << *start << std::endl;
// --start;
// std::cout << "++: " << *start << std::endl;
// --start;
// std::cout << "++: " << *start << std::endl;
// --start;
// std::cout << "++: " << *start << std::endl;
// --start;
// std::cout << "++: " << *start << std::endl;
// --start;
// std::cout << "++: " << *start << std::endl;
    


/*
*
*   List iterators post--
*
*/

// start--;
// std::cout << "++: " << *start << std::endl;
// start--;
// std::cout << "++: " << *start << std::endl;
// start--;
// std::cout << "++: " << *start << std::endl;
// start--;
// std::cout << "++: " << *start << std::endl;
// start--;
// std::cout << "++: " << *start << std::endl;
// start--;
// std::cout << "++: " << *start << std::endl;
// start--;
// std::cout << "++: " << *start << std::endl;
// start--;
// std::cout << "++: " << *start << std::endl;
// start--;
// std::cout << "++: " << *start << std::endl;
// start--;
// std::cout << "++: " << *start << std::endl;
// start--;
// std::cout << "++: " << *start << std::endl;
// start--;
// std::cout << "++: " << *start << std::endl;


/*
*
*   List iterators empty
*
*/


// s21::List list_6;
// auto it_6 = list_6.begin();

// it_6--;
// std::cout << "++: " << *it_6 << std::endl;


return 0;
}