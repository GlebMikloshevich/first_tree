#include "TreeNode.h"
#include "algorithm"
#include "iostream"
#include "iomanip"
template <class T>
TreeNode<T>::TreeNode() {
    this->data = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

template <class T>
void TreeNode<T>::insert(T d) {
    if (!this->data) {
//        std::cout<<d<<'\n';
        T* tmp_data = new T(d);
        this->data = tmp_data;
        this->right = new TreeNode<T>;
        this->left = new TreeNode<T>;
    } else if (d <= *(this->data)) {
        this->left->insert(d);
    } else {
        this->right->insert(d);
    }
}

template <class T>
TreeNode<T>* TreeNode<T>::seek(T data) {
    if (this->data == nullptr) {
        return nullptr;
    }

    if (data == *(this->data)) {
        return this;
    } else if (data < *(this->data)) {
        this->left->seek(data);
    } else if (data > *(this->data)){
        this->right->seek(data);
    }
}

template <class T>
void TreeNode<T>::remove(T data,  TreeNode<T>* root_link) {

    if (!this->data) {
        return;
    }

//    if (root_link == nullptr and *this->data == data) {
//        this->data = nullptr;
//        return;
//    }


        if (*this->data < data) {
        this->right->remove(data, this->right);
    } else if (*this->data > data) {
        this->left->remove(data, this->left);
    } else {
        if (this->left->data == nullptr && this->right->data == nullptr) {
            *root_link = *(new TreeNode<T>);
            return;
        }

        if (this->right->data == nullptr) {
            *root_link = *(this->left);
            return;
        }

        if (this->left->data == nullptr) {
            *root_link = *(this->right);
            return;
        }

        if (this->right->left->data == nullptr) {
            this->right->left = this->left;
            *root_link = *(this->right);
            return;
        }

        TreeNode<T>* r = this->right;
        while (r->left->left->data != nullptr) {
            r = r->left;
        }
        r->left->left = this->left;
        r->right->right = this->right;
        *root_link = *(r->left);
        r->left = nullptr;
    }

}

template <class T>
void TreeNode<T>::print(int indent) {
    if (this->data != nullptr) {

        this->left->print(indent + 4);
        this->right->print(indent + 4);

        if (indent)
            std::cout<<std::setw(indent) << ' ';
        std::cout<< *(this->data) <<"\n ";

    }
}