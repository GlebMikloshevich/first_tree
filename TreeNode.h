#ifndef TREE_TREENODE_H
#define TREE_TREENODE_H

template <class T>
class TreeNode {
public:
    T* data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode();
    void insert(T d);
    TreeNode<T>* seek(T data);
    void remove(T data,  TreeNode<T>* root_link);
    void print(int indent = 0);
private:
};


#endif //TREE_TREENODE_H
