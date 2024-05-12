#include <iostream>

#include <list>

#include "s21_list.h"
#include "s21_ListListNode.h"

// #include "s21_list.cc"
// #include "s21_ListNode.cc"

int main() {

    /*
    *   insert_ListNode_after_curr
    */

    // s21::ListNode* new_ListNode = new s21::ListNode;
    // new_ListNode->insert_ListNode_after_curr(2);

    // new_ListNode->print_ListNode();
    // new_ListNode->next_->print_ListNode();

    // // new_ListNode->next_->delete_current_ListNode();
    // // new_ListNode->print_ListNode();

    // new_ListNode->delete_all_ListNodes_curr_and_forward();
    // // new_ListNode->print_ListNode();


    /*
    *   insert_ListNode_before_curr
    */


/*
*
*   Test of inserts, print all and delete all
*  
*/
//    s21::ListNode* new_ptr = new s21::ListNode;
//    new_ptr->insert_ListNode_before_curr(12);
//    new_ptr->insert_ListNode_after_curr(16);
//    new_ptr->insert_ListNode_after_curr(17);
//    new_ptr->insert_ListNode_after_curr(18);
//    new_ptr->print_ListNode_all();
//    new_ptr->delete_all_ListNodes();
   
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
// list.print_all_valid_ListNodes();
// std::cout << "\nSize: " << list.size() << std::endl;
// list.pop_front();
// list.print_all_valid_ListNodes();
// list.pop_back();
// list.print_all_valid_ListNodes();
// std::cout << "\nSize: " << list.size() << std::endl;
// list.pop_back();
// list.pop_back();
// list.pop_back();
// list.pop_back();
// std::cout << "\nSize: " << list.size() << std::endl;
// list.push_front(101);
// list.push_back(999);
// list.print_all_ListNodes_with_hidden();
// std::cout << "\nlist.clear() "  << std::endl;
// list.clear();
// list.print_all_ListNodes_with_hidden();


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

// list.print_all_valid_ListNodes();

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

// list.print_all_valid_ListNodes();

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

/*
*
*   List constuctor size_t
*
*/

// s21::List list_7 = s21::List(0);
// list_7.print_all_valid_ListNodes();


/*
*
*   List constuctor initializer
*
*/

// s21::List list_8 {1,2,3,4,5,6,7,8,9, 10};
// list_8.print_all_valid_ListNodes();

// s21::List list_empty {};
// list_empty.print_all_valid_ListNodes();

// s21::List list_copy (list_8);
// list_copy.print_all_valid_ListNodes();

// s21::List<int> list_move (s21::List<int> {-1,0,1,2,3});
// std::list<int> list_std (std::list<int> {-1,0,1,2,3});
// std::list<int> list_std1 (std::list<int> {-1});
// // list_move.print_all_valid_ListNodes();
// std::cout << list_move.max_size() << std::endl;
// std::cout << list_std.max_size() << std::endl;
// std::cout << list_std1.max_size() << std::endl;

/*
*
*   List insert
*
*/

/*
*   Not My
*/ 

// std::list<int> list_insert (std::list<int> {0,1,2,3,4,5});

// std::cout << "std: ";
// for (auto it = list_insert.begin(); it != list_insert.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;

// auto it1 = list_insert.begin();
// it1++;
// list_insert.insert(it1, 10);

// std::cout << "std: ";
// for (auto it = list_insert.begin(); it != list_insert.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;

/*
*   My
*/ 

// s21::List<int> my_list_insert {0,1,2,3,4,5};
// std::cout << "my : ";
// for (auto it = my_list_insert.begin(); it != my_list_insert.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;

// auto my_it = my_list_insert.begin();
// my_it++;
// my_list_insert.insert(my_it, 10);

// std::cout << "my : ";
// for (auto it = my_list_insert.begin(); it != my_list_insert.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;


// /*
// *
// *   List erase
// *
// */

// /*
// *   Not My
// */ 

// std::list<int> list_insert (std::list<int> {0,1,2,3,4,5});

// std::cout << "std: ";
// for (auto it = list_insert.begin(); it != list_insert.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;

// auto it1 = list_insert.begin();
// it1++;
// list_insert.erase(it1);

// std::cout << "std: ";
// for (auto it = list_insert.begin(); it != list_insert.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;

// /*
// *   My
// */ 

// s21::List<int> my_list_insert {0,1,2,3,4,5};
// std::cout << "my : ";
// for (auto it = my_list_insert.begin(); it != my_list_insert.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;

// auto my_it = my_list_insert.begin();
// my_it++;
// my_list_insert.erase(my_it);

// std::cout << "my : ";
// for (auto it = my_list_insert.begin(); it != my_list_insert.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;



// /*
// *
// *   List swap
// *
// */

// /*
// *   My
// */ 

// s21::List<int> my_list_swap1 {5,4,3,2,1};
// s21::List<int> my_list_swap2 {1,2,3,4,5};
// std::cout << "1 : ";
// for (auto it = my_list_swap1.begin(); it != my_list_swap1.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;

// std::cout << "2 : ";
// for (auto it = my_list_swap2.begin(); it != my_list_swap2.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;

// // auto my_it = my_list_insert.begin();
// // my_it++;
// // my_list_insert.erase(my_it);

// my_list_swap1.swap(my_list_swap2);

// std::cout << "1 : ";
// for (auto it = my_list_swap1.begin(); it != my_list_swap1.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;

// std::cout << "2 : ";
// for (auto it = my_list_swap2.begin(); it != my_list_swap2.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;



// /*
// *
// *   List swap
// *
// */

// /*
// *   My
// */ 
// //                             -6, 1, 2, 3, 4, 5, 10, 100, 1000
// s21::List<int> my_list_sort1 {5,10, 4, 100, 3,2,1, 1000, -6};
// std::cout << "1 : ";
// for (auto it = my_list_sort1.begin(); it != my_list_sort1.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;

// my_list_sort1.sort();

// std::cout << "2 : ";
// for (auto it = my_list_sort1.begin(); it != my_list_sort1.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;


// /*
// *
// *   List merge
// *
// */

// /*
// *   My
// */ 
                            
// s21::List<int> my_list_merge1 {5,10, 4, 100, 3,2,1, 1000, -6};
// s21::List<int> my_list_merge2 {-10, -4, 0,1,2,3, 8, 99,101, 1000};

// my_list_merge1.sort();
// my_list_merge2.sort();

// std::cout << "1 : ";
// for (auto it = my_list_merge1.begin(); it != my_list_merge1.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;


// std::cout << "2 : ";
// for (auto it = my_list_merge2.begin(); it != my_list_merge2.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;

// my_list_merge1.merge(my_list_merge2);

// std::cout << "1 : ";
// for (auto it = my_list_merge1.begin(); it != my_list_merge1.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;



// /*
// *
// *   List unique
// *
// */

// /*
// *   My
// */ 
                            
// s21::List<int> my_list_unique1 {0,0, 1, 2, 3, 3, 3, 4, 5, 6, 8, 3, 2, 6};

// std::cout << "1 : ";
// for (auto it = my_list_unique1.begin(); it != my_list_unique1.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;

// my_list_unique1.unique();

// std::cout << "1 : ";
// for (auto it = my_list_unique1.begin(); it != my_list_unique1.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;


// /*
// *
// *   List reverse
// *
// */

// /*
// *   My
// */ 
                            
// s21::List<int> my_list_unique1 {1,2,3,4,5,6,7,8,9};
// // s21::List<int> my_list_unique1 {1,2,3};

// std::cout << "1 : ";
// for (auto it = my_list_unique1.begin(); it != my_list_unique1.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;

// my_list_unique1.reverse();

// std::cout << "1 : ";
// for (auto it = my_list_unique1.begin(); it != my_list_unique1.end(); it++) {
//     std::cout << *it << " ";
// }
// std::cout << std::endl;


/*
*
*   List splice
*
*/

/*
*   My
*/ 
                            
s21::List<int> my_list_splice_origin {-10,20};
s21::List<int> my_list_splice_source {1,2,3,4,5,6,7,8,9};
// s21::List<int> my_list_unique1 {1,2,3};

std::cout << "1 : ";
for (auto it = my_list_splice_origin.begin(); it != my_list_splice_origin.end(); it++) {
    std::cout << *it << " ";
}
std::cout << std::endl;

auto it = my_list_splice_origin.begin();
it++;

my_list_splice_origin.splice(it, my_list_splice_source);

std::cout << "1 : ";
for (auto it = my_list_splice_origin.begin(); it != my_list_splice_origin.end(); it++) {
    std::cout << *it << " ";
}
std::cout << std::endl;

return 0;
}