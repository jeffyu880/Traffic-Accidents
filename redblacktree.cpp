#include "redblacktree.h"
#include "node.h"

Node *RedBlackTree::InsertNode(Node *root, Node *newNode)
{
    if (root == nullptr)
    {
        root = newNode;
        return root;
    }
    else if (newNode->severityIndex > root->severityIndex)
    {
        root->right = InsertNode(root->right, newNode);
    }
    else
    {
        root->left = InsertNode(root->left, newNode);
    }
    return BalanceTree(root);
}

Node *RedBlackTree::BalanceTree(Node *root)
{
    //Case 1: tree is empty
    if (root->parent == nullptr)
    {
        root->color = false;
    }
}

//PARAMETERS CAN CHANGE
Node *RedBlackTree::SearchNode(int severityIndex)
{
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