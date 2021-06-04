#include <iostream>
#include "TreeNode.h"
#include "TreeNode.cpp"
int main() {
    TreeNode<int> tree;
    tree.insert(10);
    tree.insert(9);
    tree.insert(20);
    tree.insert(15);
    tree.insert(12);
    tree.insert(16);


    tree.insert(21);

    tree.remove(30, nullptr);
    TreeNode<int>* t = tree.seek(30);
    if (t == nullptr) {
        std::cout<<"NULL"<<"\n\n\n";
    } else {
        std::cout<<t->data<<"\n\n\n";
    }

    tree.print(0);
}
