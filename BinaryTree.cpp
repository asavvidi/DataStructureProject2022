#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "string.h"
#include <cstring>

using namespace std;
//Constructor, creating the tree.
BinaryTree::BinaryTree()
{
    root = NULL;
}

//public function add
void BinaryTree::add(string x)
{
    root = add(x, root);
}

//private function add
BinaryTree::node* BinaryTree::add(string x, node* t)
{
    if (t == NULL)
    {
        //Tree is empty, new word x
        //creating a new node for x,initializing appearances and children
        t = new node;
        t->data = x;
        t->a = 1;
        t->left = t->right = NULL;
    }
    //searching the right place of this word (string x)
    else if (x < t->data)
        t->left = add(x, t->left);
    else if (x > t->data)
        t->right = add(x, t->right);
    //word already there, increasing appearance of x
    else if (x == t->data)
        t->a = t->a + 1;
    return t;
}

BinaryTree::node* BinaryTree::getRoot()
{
    return root;
}


//public function in order
void BinaryTree::inorder()
{
    cout << "Inorder : " << endl;
    inorder(root);
}


//private function in order
void BinaryTree::inorder(node* t)
{
    if (t == NULL)
        return;
    inorder(t->left);
    cout << t->data << " " << t->a << endl;
    inorder(t->right);
}


//public function pre order
void BinaryTree::preorder()
{
    cout << "Preorder : " << endl;
    preorder(root);
}


//private function pre order
void BinaryTree::preorder(node* t)
{
    if (t == NULL)
        return;
    cout << t->data << " " << t->a << endl;
    preorder(t->left);
    preorder(t->right);
}


//public function post order
void BinaryTree::postorder()
{
    cout << "Postorder : " << endl;
    postorder(root);
}


//private function post order
void BinaryTree::postorder(node* t)
{
    if (t == NULL)
        return;
    postorder(t->left);
    postorder(t->right);
    cout << t->data << " " << t->a << endl;
}

//public function searching.
void BinaryTree::searching(string x)
{
    node* t;
    t = finding(x, root); //get node of searching word (x)
//If word is found print data(appearances) else print "not found"
    if (t == NULL)
        cout << "Word '" << x << "' not found." << endl;
    else
        cout << x << "(" << t->a << ")" << endl;
}


BinaryTree::node* BinaryTree::finding(string x, node* t)
{
    if (t == NULL)   //empty tree or end of tree, word not found
        return NULL;
    else if (x < t->data) //word smaller than current node
        return finding(x, t->left);
    else if (x > t->data) //word bigger than current node
        return finding(x, t->right);
    else
        return t; //word found
}


//private function deleting
BinaryTree::node* BinaryTree::deleting(string x, node* t)
{
    node* temp;
    if (t == NULL)
        return NULL;
    //x smaller than t's key, go to left subtree
    else if (x < t->data)
        t->left = deleting(x, t->left);
    //x bigger than t's key, go to right subtree
    else if (x > t->data)
        t->right = deleting(x, t->right);
    //node to be deleted found
    else if (t->left && t->right) //node with two children
    {
        //deleting node and replacing it with smallest node of right subtree
        temp = FindMin(t->right);
        t->data = temp->data;
        t->right = deleting(t->data, t->right);
    }
    else //node with one child or none
    {
        temp = t;
        if (t->left == NULL) //replaced with the right child
            t = t->right;
        else if (t->right == NULL) //replaced with the left child
            t = t->left;
        delete temp;
    }
    return t;
}


//Finding smallest node of a subtree
BinaryTree::node* BinaryTree::FindMin(node* t)
{
    while (t->left != NULL)
        t = t->left;
    return t;
}


//public function removing
void BinaryTree::removing(string x)
{
    root = deleting(x, root);
    if (root == NULL)
        cout << "Word '" << x << "' not found. Can't delete it" << endl;
    else
    {
        cout << "Word '" << x << "' deleted" << endl;
    }
}


//Overloading operators <,>,==
bool operator<(const string x, const string y)
{
    if (strcmp(x.c_str(), y.c_str()) < 0)
        return true;
    return false;
}


bool operator>(const string x, const string y)
{
    if (x < y)
        return false;
    return true;
}


bool operator==(const string x, const string y)
{
    if (strcmp(x.c_str(), y.c_str()) == 0)
        return true;
    return false;
}
