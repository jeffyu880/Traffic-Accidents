#include "redblacktree.h"
#include "node.h"
#include <iostream>

using namespace std;

Node *RedBlackTree::FindLeastSevereAccident()
{
    return GetmostSevereAccident(mainRoot);
}

Node *RedBlackTree::FindMostSevereAccident()
{
    return GetleastSevereAccident(mainRoot);
}

void RedBlackTree::InsertNode(Node *newNode)
{
    mainRoot = Insert(mainRoot, newNode);
    BalanceTree(mainRoot, newNode);
}

Node *RedBlackTree::SearchNode(int severitytoFind)
{
    return Search(mainRoot, severitytoFind);
}

Node *RedBlackTree::Insert(Node *root, Node *newNode)
{
    if (root == nullptr)
    {
        root = newNode;
        return root;
    }
    else if (newNode->severityIndex > root->severityIndex)
    {
        root->right = Insert(root->right, newNode);
        root->right->parent = root;
    }
    else
    {
        root->left = Insert(root->left, newNode);
        root->left->parent = root;
    }
    return root;
}

//PARAMETERS CAN CHANGE
Node *RedBlackTree::Search(Node *root, int severitytoFind)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else if (severitytoFind == root->severityIndex)
    {
        return root;
    }
    else if (severitytoFind > root->severityIndex)
    {
        return Search(root->right, severitytoFind);
    }
    else
    {
        return Search(root->left, severitytoFind);
    }
}

void RedBlackTree::PrintInorder()
{
    printingInorder(mainRoot);
}

void RedBlackTree::PrintPreorder()
{
}

void RedBlackTree::PrintPostorder()
{
}

/*****************************REFERENCES*********************/
/*Source: Cheryl Resch video on Red Black Tree for BalanceTree
https://mediasite.video.ufl.edu/Mediasite/Play/dd2c7230add6482e87e0c371fb3988931d
 Code: BalanceTree
 ************************************************************/
void RedBlackTree::BalanceTree(Node *root, Node *node)
{
    //Case 1: tree is empty (no parent node, root is mainRoot)
    if (node->parent == nullptr)
    {
        node->color = true; //color it black
        return;
    }

    //Case 2: if tree is not empty, create a new node as a leaf node with color red
    //If parent of node is black, exit

    if (node->parent->color == true)
    { //parent is black, so no rules broken, return
        return;
    }

    //Case 3: parent is red
    Node *uncle = getUncle(node);
    Node *grandparent = getGrandparent(node);
    Node *parent = node->parent;
    //Case 3a: if uncle is red, flip the colors of parent and uncle and grandparent and check for imbalances of grandparent
    if (uncle != nullptr && uncle->color == false)
    {
        parent->color = true;
        uncle->color = true;
        grandparent->color = false;
        BalanceTree(root, grandparent);
        return;
    }
    //Case 3b: red parent, no red uncle, left right imbalance
    if (node == parent->right && parent == grandparent->left)
    {
        RotateLeft(root, parent);
        node = parent;
        parent = node->parent;
    }
    //Case 3c: red parent, no red uncle, right left imbalance
    else if (node == parent->left && parent == grandparent->right)
    {
        RotateRight(root, parent);
        node = parent;
        parent = node->parent;
    }
    //Case 4a: red parent, no red uncle, and left imbalance about grandparent
    parent->color = true;
    grandparent->color = false;
    if (node == parent->left)
    {
        RotateRight(root, grandparent);
    }
    //Case 4b: red parent, no red uncle and right imbalance about grandparent
    else
    {
        RotateLeft(root, grandparent);
    }
}

void RedBlackTree::printingInorder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    printingInorder(node->left);
    //cout << node->severityIndex << " ";
    // if (node->color == false)
    // {
    //     cout << "red" << endl;
    // }
    // else
    // {
    //     cout << "black" << endl;
    // }
    treesize++;
    printingInorder(node->right);
}
/*****************************REFERENCES*********************/
/*Source: Introduction to Algorithms by Thomas H. Cormen
 Code:  RotateLeft and RotateRight Functions
 ************************************************************/
void RedBlackTree::RotateLeft(Node *root, Node *node)
{
    Node *newRoot = node->right;
    //setting the node's right subtree equal to newRoot's left subtree
    node->right = newRoot->left;
    //newRoot's left parent is node's parent
    if (newRoot->left != nullptr)
    {
        newRoot->left->parent = node;
    }
    newRoot->parent = node->parent;
    //if node does not have a parent, newRoot becomes the mainRoot of tree
    if (node->parent == nullptr)
    {
        mainRoot = newRoot;
    }
    //configuring the parent of node to print to newRoot
    else if (node == node->parent->left)
    {
        node->parent->left = newRoot;
    }
    else
    {
        node->parent->right = newRoot;
    }
    newRoot->left = node;
    node->parent = newRoot;
    return;
}

void RedBlackTree::RotateRight(Node *root, Node *node)
{
    Node *newRoot = node->left;
    //newRoot->parent = node->parent;
    node->left = newRoot->right;
    if (newRoot->right != nullptr)
    {
        newRoot->right->parent = node;
    }
    newRoot->parent = node->parent;
    if (node->parent == nullptr)
    {
        mainRoot = newRoot;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = newRoot;
    }
    else
    {
        node->parent->right = newRoot;
    }
    newRoot->right = node;
    node->parent = newRoot;
    return;
}

Node *RedBlackTree::getGrandparent(Node *node)
{
    return node->parent->parent;
}

Node *RedBlackTree::getUncle(Node *node)
{
    if (node->parent->parent->left == node->parent)
    {
        return node->parent->parent->right;
    }
    else
    {
        return node->parent->parent->left;
    }
}

Node *RedBlackTree::GetmostSevereAccident(Node *root)
{
    if (root->right == nullptr)
    {
        return root;
    }
    else
    {
        return GetmostSevereAccident(root->right);
    }
}

Node *RedBlackTree::GetleastSevereAccident(Node *root)
{
    if (root->left == nullptr)
    {
        return root;
    }
    else
    {
        return GetleastSevereAccident(root->left);
    }
}