#include "node.h"

class RedBlackTree
{
private:
    Node *mainRoot;
    Node *BalanceTree(Node *node);
    Node *RotateLeft(Node *node);
    Node *RotateRight(Node *node);
    Node *RedBlackTree::RotateLeftRight(Node *node);
    Node *RedBlackTree::RotateRightLeft(Node *node);

public:
    Node *InsertNode(Node *root, Node *newNode);
    Node *SearchNode(int severityIndex);
};