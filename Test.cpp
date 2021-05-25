#include "doctest.h"
#include "BinaryTree.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include <cstring>

using namespace ariel;
using namespace std;


TEST_CASE("simple test begin and end iterators"){
    BinaryTree<int> tree_of_ints;
    BinaryTree<string> tree_of_string;
    BinaryTree<char> tree_of_char;

    // begin
    auto iter_pre = tree_of_ints.begin_preorder();
    auto iter_in = tree_of_string.begin_inorder();
    auto iter_post = tree_of_string.begin_postorder();

    CHECK(iter_pre == nullptr);
    CHECK(iter_in == nullptr);
    CHECK(iter_post == nullptr);

    // end
    auto end_pre = tree_of_ints.begin_preorder();
    auto end_in = tree_of_string.begin_inorder();
    auto end_post = tree_of_string.begin_postorder();
    
    CHECK(end_pre ==  nullptr);
    CHECK(end_in ==  nullptr);
    CHECK(end_post ==  nullptr);
}


TEST_CASE("test mathod add_root"){
    BinaryTree<int> tree_of_ints;
    BinaryTree<string> tree_of_string;
    BinaryTree<double> tree_of_double;

    tree_of_ints.add_root(1);
    tree_of_string.add_root("root");
    tree_of_double.add_root(0.5);

    auto iter_pre = tree_of_ints.begin_preorder();
    auto iter_in = tree_of_string.begin_inorder();
    auto iter_post = tree_of_double.begin_postorder();

    CHECK((*iter_pre) == 1);
    CHECK((*iter_in) == "root");
    CHECK((*iter_post) == 0.5);

    // replace existing root:
    tree_of_ints.add_root(2);
    tree_of_string.add_root("new_root");
    tree_of_double.add_root(3.5);

    auto iter_pre2 = tree_of_ints.begin_preorder();
    auto iter_in2 = tree_of_string.begin_inorder();
    auto iter_post2 = tree_of_double.begin_postorder();

    CHECK((*iter_pre2) == 2);
    CHECK((*iter_in2) == "new_root");
    CHECK((*iter_post2) == 3.5);

}


TEST_CASE("test mathod add_right"){
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(0);
    CHECK_THROWS(tree_of_ints.add_right(-1,2));
    CHECK_NOTHROW(tree_of_ints.add_right(0,1).add_right(1,2));

    int i =0;
    for (auto it=tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder(); ++it){
        CHECK((*it) == i);
        ++i;
    }

    // replace existing value:
    CHECK_NOTHROW(tree_of_ints.add_right(0,10).add_right(1,20));
    int j = 0;
    for (auto it=tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder(); ++it){
        CHECK((*it) == j*10);
        ++j;
    } 
}


TEST_CASE("test mathod add_left"){
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(0);
    CHECK_THROWS(tree_of_ints.add_left(-10,2));
    CHECK_THROWS(tree_of_ints.add_left(100,2));
    CHECK_NOTHROW(tree_of_ints.add_left(0,2));
    CHECK_NOTHROW(tree_of_ints.add_left(2,4));

    int i =0;
    for (auto it=tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder(); ++it){
        CHECK((*it) == i*2);
        ++i;
    }

    // replace existing value:
    CHECK_NOTHROW(tree_of_ints.add_right(0,20).add_right(1,40));
    int j =0;
    for (auto it=tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder(); ++it){
        CHECK((*it) == j*20);
        ++j;
    }
}


TEST_CASE("test preorder"){
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1).add_left(1,2).add_left(2,3).add_right(2,4);
    tree_of_ints.add_right(1,5).add_left(5,6).add_right(5,7);
    int i=1;
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it){
        CHECK((*it) == i);                
        i++;
    }
}


TEST_CASE("test inorder"){
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(4).add_left(4,2).add_left(2,1).add_right(2,3);
    tree_of_ints.add_right(4,6).add_left(6,5).add_right(6,7);
    int i=1;
    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it){
        CHECK((*it) == i);              
        i++;
    }
}


TEST_CASE("test postrder"){
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(7).add_left(7,3).add_left(3,1).add_right(3,2);
    tree_of_ints.add_right(7,6).add_left(6,4).add_right(6,5);
    int i=1;
    for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it){
        CHECK((*it) == i);                 
        i++;
    }
}









