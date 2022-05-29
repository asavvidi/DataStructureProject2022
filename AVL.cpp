#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "AVL.h"
#include "string.h"
#include <cstring>

using namespace std;
//constructor
AVL::AVL() :BinaryTree()
{
    root = NULL;
}


//public function add
void AVL::add(string x)
{
    root = add(x, root);
}


//public function removing
void AVL::removing(string x)
{
    root = deleting(x, root);
    if (root == NULL)
        cout << "Word '" << x << "' not found. Can't delete it" << endl;
    else
    {
        cout << "Word '" << x << "' deleted" << endl;
    }
}


//get Max of two integers
int AVL::getMax(int a, int b)
{
    if (a > b)
        return a;
    return b;
}


//get Height of a subtree
int AVL::getHeight(node* t)
{
    if (t == NULL)
        return 0;
    return t->height;
}


//get Balance of a node
int AVL::getBalance(node* t)
{
    if (t == NULL)
        return 0;
    return getHeight(t->left) - getHeight(t->right);
}


//performing right Rotation
AVL::node* AVL::rightRotate(node* t)
{
    node* t1 = t->left;
    node* t2 = t1->right;
    t1->right = t;
    t->left = t2;
    t->height = getMax(getHeight(t->left), getHeight(t->right)) + 1;
    t1->height = getMax(getHeight(t1->left), getHeight(t1->right)) + 1;
    return t1;
}


//performing left Rotation
AVL::node* AVL::leftRotate(node* t)
{
    node* t1 = t->right;
    node* t2 = t1->left;
    t1->left = t;
    t->right = t2;
    t->height = getMax(getHeight(t->left), getHeight(t->right)) + 1;
    t1->height = getMax(getHeight(t1->left), getHeight(t1->right)) + 1;
    return t1;
}


AVL::node* AVL::add(string x, node* t)
{
    if (t == NULL)
    {
        //New word, creating a new node
        t = new node;
        //Initialize data,appearances,height,children
        t->data = x;
        t->a = 1;
        t->height = 1;
        t->left = t->right = NULL;
    }
    //x smaller than t's data ,go to left subtree
    else if (x < t->data)
        t->left = add(x, t->left);
    //x bigger than t's data ,go to right subtree
    else if (x > t->data)
        t->right = add(x, t->right);
    //x already there, increase its appearances
    else if (x == t->data)
        t->a = t->a + 1;
    //One more word added, increase height
    t->height = 1 + getMax(getHeight(t->left), getHeight(t->right));
    //checking if tree gets unbalanced
    int balance = getBalance(t);
    //Case 1:Left Left.
    if (balance > 1 && x < t->left->data)
        return rightRotate(t);
    //Case 2:Right Right.
    if (balance< -1 && x>t->right->data)
        return leftRotate(t);
    //Case 3: Left Right.
    if (balance > 1 && x > t->left->data)
    {
        t->left = leftRotate(t->left);
        return rightRotate(t);
    }
    //Case 4: Right Left.
    if (balance < -1 && x < t->right->data)
    {
        t->right = rightRotate(t->right);
        return leftRotate(t);
    }
    return t;
}


AVL::node* AVL::deleting(string x, node* t)
{
    node* temp;
    if (t == NULL)
        return t;
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

    //If had only one node.
    if (t == NULL)
        return t;
    //Increasing height because of the replacement
    t->height = 1 + getMax(getHeight(t->left), getHeight(t->right));
    //Checking if node gets unbalanced
    int balance = getBalance(t);

    //Case 1: Left Left Case.
    if (balance > 1 && getBalance(t->left) >= 0)
        return rightRotate(t);
    //Case 2: Right Right Case.
    if (balance < -1 && getBalance(t->right) <= 0)
        return leftRotate(t);
    //Case 3: Left Right.
    if (balance > 1 && getBalance(t->left) < 0)
    {
        t->left = leftRotate(t->left);
        return rightRotate(t);
    }
    //Case 4: Right Left.
    if (balance < -1 && getBalance(t->right) > 0)
    {
        t->right = rightRotate(t->right);
        return leftRotate(t);
    }
    return t;
}
