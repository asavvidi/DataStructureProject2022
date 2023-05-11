#ifndef AVL_H
#define AVL_H
#include <string>
#include <iostream>
#include "BinaryTree.h"

using namespace std;

class AVL : public BinaryTree //inherit from class BinaryTree
{
private:
    int getBalance(node* t);
    int getHeight(node* t);
    int getMax(int a, int b);
    node* leftRotate(node* t);
    node* rightRotate(node* t);
    node* add(string x, node* t);
    node* deleting(string x, node* t);
    
public:
    AVL();
    void add(string x);
    void removing(string x);
};
#endif // AVL_H

