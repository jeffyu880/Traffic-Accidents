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
    //Case 1: tree is empty
    if (root->parent == nullptr)
    {
        root->color = false;
    }
    //Case 2: if tree is not empty, create a new node as a leaf node with color red
    //If parent of node is black, exit

    //If parent of node is red, check sibling of parent

    //if color is black, rotate and recolor

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