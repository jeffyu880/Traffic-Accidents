#include "node.h"
#include "redblacktree.h"
#include <iostream>
using namespace std;

int main()
{
    RedBlackTree *tree = new RedBlackTree();
    Node *newNode = new Node(123);
    tree->InsertNode(newNode);
    newNode = new Node(22);
    tree->InsertNode(newNode);
    newNode = new Node(32);
    tree->InsertNode(newNode);
}