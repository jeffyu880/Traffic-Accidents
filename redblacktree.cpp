#include "redblacktree.h"
#include "node.h"

Node *RedBlackTree::InsertNode(Node *newNode)
{
    mainRoot = Insert(mainRoot, newNode);
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
        newNode->parent = root;
    }
    else
    {
        root->left = Insert(root->left, newNode);
        newNode->parent = root;
    }
    return BalanceTree(root);
}

Node *RedBlackTree::BalanceTree(Node *root)
{
    //Case 1: tree is empty (no parent node, root is mainRoot)
    if (root->parent == nullptr)
    {
        root->color = true; //color it black
    }

    //Case 2: if tree is not empty, create a new node as a leaf node with color red
    //If parent of node is black, exit

    if (root->parent->color == true){ //parent is black, so no rules broken, return
	    return root;
    }

    //else parent is red, and you must check uncle

    Node* uncle;


    if (root->parent->parent->left == root->parent) {
        uncle = root->parent->parent->right;
    }
    else {
        uncle = root->parent->parent->left;
    }

    //if uncle is null or black:
    if ((uncle == nullptr) || (uncle->color == true)) {
        Node* grandparent = root->parent->parent;
        //code to help find what kind of imbalance is occurring
        if (grandparent->left == root->parent) {
            if (root->parent->left == root) {
                rotateRight(grandparent);
                BalanceTree(node->parent);
            }
            else {
                rotateLeftRight(grandparent);
                BalanceTree(node);
            }
        }
        else {
            if (root->parent->left == root) {
                rotateRightLeft(grandparent);
                BalanceTree(node);
            }
            else {
                rotateLeft(grandparent);
                BalanceTree(node->parent);
            }
        }

    }
    //else its red:
    else {
        //flip colors
        root->color = true;
        root->parent->color = false;
        uncle->color = false;
        //root is correct, now make sure that the parent now satisfies the rules
        BalanceTree(root->parent);
    }
        


   

    //if red, recolor the node,
}

Node *RedBlackTree::SearchNode(int severitytoFind)
{
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
        return Search(root->left, severitytoFind);
    }
    else
    {
        return Search(root->right, severitytoFind);
    }
}

Node *RedBlackTree::RotateLeft(Node *node)
{
    Node *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    return newRoot;
}

Node *RedBlackTree::RotateRight(Node *node)
{
    Node *newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    return newRoot;
}

Node *RedBlackTree::RotateLeftRight(Node *node)
{
    node->left = RotateLeft(node->left);
    return RotateRight(node);
}

Node *RedBlackTree::RotateRightLeft(Node *node)
{
    node->right = RotateRight(node->right);
    return RotateLeft(node);
}