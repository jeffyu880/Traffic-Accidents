#include "node.h"
#include <vector>
#pragma once

class RedBlackTree
{
private:
<<<<<<< HEAD
    //Node* mainRoot = nullptr;
    void BalanceTree(Node* root, Node* node);
    void RotateLeft(Node* root, Node* node);
    void RotateRight(Node* root, Node* node);
    Node* Insert(Node* root, Node* node);
    Node* getUncle(Node* root);
    Node* getGrandparent(Node* root);
    void printingInorder(Node* root);
    //SEARCH FUNCTIONS
    Node* Search(Node* root, int severitytoFind);
    Node* GetmostSevereAccident(Node* root);
    Node* GetleastSevereAccident(Node* root);
    void GetXmostSevereAccidents(Node* root, int& numAccidents, vector<Node*>& Accidents);
    void GetXleastSevereAccidents(Node* root, int& numAccidnets, vector<Node*>& Accidents);
    void GetXmostSevereCityAccidents(Node* root, int& numAccidents, string city, vector<Node*>& Accidents);
    void GetXmostSevereStateAccidents(Node* root, int& numAccidents, string state, vector<Node*>& Accidents);
    void GetXmostSevereAccidentsInYear(Node* root, int& numAccidents, int year, vector<Node*>& Accidents);

public:
    int height();
    Node* mainRoot = nullptr;
    int maxDepth(Node* root);
    int getHeight(Node* root);
    void InsertNode(Node* newNode);
    Node* SearchNode(int severitytoFind);
    Node* FindMostSevereAccident();
    Node* FindLeastSevereAccident();
    void FindXMostSevereAccidents(int numAccidents, vector<Node*>& Accidents);
    void FindXLeastSevereAccidents(int numAccidents, vector<Node*>& Accidents);
    void FindXMostSevereAccidentsInCity(int numAccidents, string city, vector<Node*>& Accidents);
    void FindXMostSevereAccidentsInState(int numAccidents, string state, vector<Node*>& Accidents);
    void FindXMostSevereAccidentsInYear(int numAccidents, int year, vector<Node*>& Accidents);
=======
    Node *mainRoot = nullptr;
    void BalanceTree(Node *root, Node *node);
    void RotateLeft(Node *root, Node *node);
    void RotateRight(Node *root, Node *node);
    Node *Insert(Node *root, Node *node);
    Node *getUncle(Node *root);
    Node *getGrandparent(Node *root);
    void printingInorder(Node *root);
    //SEARCH FUNCTIONS
    Node *Search(Node *root, int severitytoFind);
    Node *GetmostSevereAccident(Node *root);
    Node *GetleastSevereAccident(Node *root);
    void GetXmostSevereAccidents(Node *root, int &numAccidents, vector<Node *> &Accidents);
    void GetXleastSevereAccidents(Node *root, int &numAccidnets, vector<Node *> &Accidents);
    void GetXmostSevereCityAccidents(Node *root, int &numAccidents, string city, vector<Node *> &Accidents);
    void GetXmostSevereStateAccidents(Node *root, int &numAccidents, string state, vector<Node *> &Accidents);
    void GetXmostSevereAccidentsInYear(Node *root, int &numAccidents, int year, vector<Node *> &Accidents);

public:
    void InsertNode(Node *newNode);
    Node *SearchNode(int severitytoFind);
    Node *FindMostSevereAccident();
    Node *FindLeastSevereAccident();
    void FindXMostSevereAccidents(int numAccidents, vector<Node *> &Accidents);
    void FindXLeastSevereAccidents(int numAccidents, vector<Node *> &Accidents);
    void FindXMostSevereAccidentsInCity(int numAccidents, string city, vector<Node *> &Accidents);
    void FindXMostSevereAccidentsInState(int numAccidents, string state, vector<Node *> &Accidents);
    void FindXMostSevereAccidentsInYear(int numAccidents, int year, vector<Node *> &Accidents);
>>>>>>> parent of c30659e (Changes made on 8/1)

    //TESTING
    int treesize = 0;
    void PrintPreorder();
    void PrintPostorder();
    void PrintInorder();
};
