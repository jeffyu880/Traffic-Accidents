#include "node.h"
#pragma once

class RedBlackTree
{
private:
    Node *mainRoot;
    Node *BalanceTree(Node *node);
    Node *RotateLeft(Node *node);
    Node *RotateRight(Node *node);
    Node *RotateLeftRight(Node *node);
    Node *RotateRightLeft(Node *node);

public:
    Node *InsertNode(Node *root, Node *newNode);
    Node *SearchNode(int severityIndex);
};