#include "node.h"
#pragma once

class RedBlackTree
{
private:
    Node *mainRoot = nullptr;
    void BalanceTree(Node *root, Node *node);
    void RotateLeft(Node *root, Node *node);
    void RotateRight(Node *root, Node *node);
    Node *Insert(Node *root, Node *node);
    Node *Search(Node *root, int severitytoFind);
    Node *getUncle(Node *root);
    Node *getGrandparent(Node *root);
    void printingInorder(Node *root);
    Node *GetmostSevereAccident(Node *root);
    Node *GetleastSevereAccident(Node *root);

public:
    void InsertNode(Node *newNode);
    Node *SearchNode(int severitytoFind);
    Node *FindMostSevereAccident();
    Node *FindLeastSevereAccident();

    //TESTING
    int treesize = 0;
    void PrintPreorder();
    void PrintPostorder();
    void PrintInorder();
};