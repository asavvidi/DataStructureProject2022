#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>
#include <iostream>

using namespace std;

class BinaryTree
{
protected:
    struct node
    {
        string data;  //word
        int a;        //appearances of the word
        int height;   //height of the tree
        node* left;   //pointer to left child
        node* right;  //pointer to right child
    };
    node* root;   //pointer to root of the tree
    virtual node* add(string x, node* t);
    node* finding(string x, node* t);
    virtual node* deleting(string x, node* t);
    node* FindMin(node* t);
    void inorder(node* t);
    void preorder(node* t);
    void postorder(node* t);
public:
    BinaryTree();
    virtual void add(string x);
    node* getRoot();
    void inorder();
    void preorder();
    void postorder();
    void searching(string x);
    virtual void removing(string x);
    friend bool operator<(string x, string y);
    friend bool operator>(string x, string y);
    friend bool operator==(string x, string y);
};

#endif // BINARYTREE_H