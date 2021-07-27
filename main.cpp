#include "node.h"
#include "redblacktree.h"
#include <iostream>
using namespace std;

int main()
{
    RedBlackTree *tree = new RedBlackTree();
    Node *newNode = new Node(3, "atlanta", "georgia", 2020);
    tree->InsertNode(newNode);
    newNode = new Node(2, "atlanta", "rhode island", 2020);
    tree->InsertNode(newNode);
    newNode = new Node(1, "decatur", "georgia", 2010);
    tree->InsertNode(newNode);
    newNode = new Node(4, "rhombus", "georgia", 2000);
    tree->InsertNode(newNode);
    newNode = new Node(5, "atlanta", "georgia", 2020);
    tree->InsertNode(newNode);
    // for (int i = 45; i < 10000; i++)
    // {
    //     newNode = new Node(float(i));
    //     tree->InsertNode(newNode);
    // }

    tree->PrintInorder();
    cout << "size: " << tree->treesize;
    Node *searchedNode = tree->SearchNode(4);
    cout << "searchedNode: " << searchedNode->severityIndex << endl;
    Node *mostSevere = tree->FindLeastSevereAccident();
    Node *leastSevere = tree->FindMostSevereAccident();
    vector<Node *> accidents;
    tree->FindXMostSevereAccidentsInYear(3, 2010, accidents);
    for (int i = 0; i < accidents.size(); i++)
    {
        cout << accidents.at(i)->severityIndex << " ";
    }
}