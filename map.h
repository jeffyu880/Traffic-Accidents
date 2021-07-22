#include "redblacktree.h"
#pragma once;

class Map
{
private:
    RedBlackTree *tree;

public:
    int size();
    void clear();
    void erase();
    void insert(pair<string, Node *>);
    bool empty();
};