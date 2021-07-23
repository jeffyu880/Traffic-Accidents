#include "node.h"
#pragma once

class RedBlackTree
{
private:
    Node *mainRoot = nullptr;
    Node *BalanceTree(Node *node);
    Node *RotateLeft(Node *node);
    Node *RotateRight(Node *node);
    Node *RotateLeftRight(Node *node);
    Node *RotateRightLeft(Node *node);
    Node *Insert(Node *root, Node *node);
    Node *Search(Node *root, int severitytoFind);

public:
    Node *InsertNode(Node *newNode);
    Node *SearchNode(int severitytoFind);
};