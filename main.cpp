#include "node.h"
#include "redblacktree.h"
#include <iostream>
using namespace std;

int main()
{
    RedBlackTree *tree = new RedBlackTree();
    Node *newNode = new Node(3);
    tree->InsertNode(newNode);
    newNode = new Node(1);
    tree->InsertNode(newNode);
    newNode = new Node(2);
    tree->InsertNode(newNode);
    newNode = new Node(4);
    tree->InsertNode(newNode);
    newNode = new Node(34);
    tree->InsertNode(newNode);
    // for (int i = 45; i < 10000; i++)
    // {
    //     newNode = new Node(float(i));
    //     tree->InsertNode(newNode);
    // }

    tree->PrintInorder();
    cout << "size: " << tree->treesize;
    Node *searchedNode = tree->SearchNode(4);
    cout << "searchedNode: " << searchedNode->severityIndex;
    Node *mostSevere = tree->FindLeastSevereAccident();
    Node *leastSevere = tree->FindMostSevereAccident();
}