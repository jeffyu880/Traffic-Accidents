#include "redblacktree.h"
#include "node.h"
#include <iostream>

using namespace std;

/***********************PUBLIC SEARCH FUNCTIONS************************/
<<<<<<< HEAD

int RedBlackTree::height() {
    //return getHeight(mainRoot);
    return maxDepth(mainRoot);
}

int RedBlackTree::maxDepth(Node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}


int RedBlackTree::getHeight(Node* root) { //returns the height of a subtree given a root node

    std::vector<Node*> currNodes;
    currNodes.push_back(root);
    int height = 1;
    if (root == NULL) {
        return 0;
    }
    while (1) {  //loop which for each level of the tree (starting at the root) increments the height if there are any children of the current level
        std::vector<Node*> newNodes;
        for (auto iter = currNodes.begin(); iter != currNodes.end(); iter++) {
            if ((*iter)->left != NULL) {
                newNodes.push_back((*iter)->left);
            }
            if ((*iter)->right != NULL) {
                newNodes.push_back((*iter)->right);
            }

        }
        if (newNodes.size() == 0) { //this process is repeated until a level is reached where no new children are found (this is end of tree and height is returned)
            return height;
        }
        else {
            height++;
            currNodes = newNodes;
        }
    }
}

Node* RedBlackTree::FindMostSevereAccident()
=======
Node *RedBlackTree::FindMostSevereAccident()
>>>>>>> parent of c30659e (Changes made on 8/1)
{
    return GetleastSevereAccident(mainRoot);
}

Node *RedBlackTree::FindLeastSevereAccident()
{
    return GetmostSevereAccident(mainRoot);
}

void RedBlackTree::FindXMostSevereAccidents(int numAccidents, vector<Node *> &Accidents)
{

    GetXmostSevereAccidents(mainRoot, numAccidents, Accidents);
    return;
}
void RedBlackTree::FindXLeastSevereAccidents(int numAccidents, vector<Node *> &Accidents)
{

    GetXleastSevereAccidents(mainRoot, numAccidents, Accidents);
    return;
}

void RedBlackTree::FindXMostSevereAccidentsInCity(int numAccidents, string city, vector<Node *> &Accidents)
{

    GetXmostSevereCityAccidents(mainRoot, numAccidents, city, Accidents);
    return;
}
void RedBlackTree::FindXMostSevereAccidentsInState(int numAccidents, string state, vector<Node *> &Accidents)
{

    GetXmostSevereStateAccidents(mainRoot, numAccidents, state, Accidents);
    return;
}

<<<<<<< HEAD
void RedBlackTree::FindXMostSevereAccidentsInYear(int numAccidents, int year, vector<Node*>& Accidents)
=======
void RedBlackTree::FindXMostSevereAccidentsInYear(int numAccidents, int year, vector<Node *> &Accidents)
>>>>>>> parent of c30659e (Changes made on 8/1)
{

    GetXmostSevereAccidentsInYear(mainRoot, numAccidents, year, Accidents);
    return;
}

/*****************************************************************************/
void RedBlackTree::InsertNode(Node *newNode)
{
    mainRoot = Insert(mainRoot, newNode);
    BalanceTree(mainRoot, newNode);
}

Node *RedBlackTree::SearchNode(int severitytoFind)
{
    return Search(mainRoot, severitytoFind);
}

/***************************PRIVATE FUNCTIONS***********************************/
Node *RedBlackTree::Insert(Node *root, Node *newNode)
{
    if (root == nullptr)
    {
        root = newNode;
        treesize++;
        return root;
    }
    else if (newNode->severityIndex > root->severityIndex)
    {
        root->right = Insert(root->right, newNode);
        root->right->parent = root;
    }
    else
    {
        root->left = Insert(root->left, newNode);
        root->left->parent = root;
    }
    
    return root;
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
        return Search(root->right, severitytoFind);
    }
    else
    {
        return Search(root->left, severitytoFind);
    }
}

void RedBlackTree::PrintInorder()
{
    printingInorder(mainRoot);
}

void RedBlackTree::PrintPreorder()
{
}

void RedBlackTree::PrintPostorder()
{
}

/*****************************REFERENCES*********************/
/*Source: Cheryl Resch video on Red Black Tree for BalanceTree
https://mediasite.video.ufl.edu/Mediasite/Play/dd2c7230add6482e87e0c371fb3988931d
 Code: BalanceTree
 ************************************************************/
void RedBlackTree::BalanceTree(Node *root, Node *node)
{
    //Case 1: tree is empty (no parent node, root is mainRoot)
    if (node->parent == nullptr)
    {
        node->color = true; //color it black
        return;
    }

    //Case 2: if tree is not empty, create a new node as a leaf node with color red
    //If parent of node is black, exit

    if (node->parent->color == true)
    { //parent is black, so no rules broken, return
        return;
    }

    //Case 3: parent is red
    Node *uncle = getUncle(node);
    Node *grandparent = getGrandparent(node);
    Node *parent = node->parent;
    //Case 3a: if uncle is red, flip the colors of parent and uncle and grandparent and check for imbalances of grandparent
    if (uncle != nullptr && uncle->color == false)
    {
        parent->color = true;
        uncle->color = true;
        grandparent->color = false;
        BalanceTree(root, grandparent);
        return;
    }
    //Case 3b: red parent, no red uncle, left right imbalance
    if (node == parent->right && parent == grandparent->left)
    {
        RotateLeft(root, parent);
        node = parent;
        parent = node->parent;
    }
    //Case 3c: red parent, no red uncle, right left imbalance
    else if (node == parent->left && parent == grandparent->right)
    {
        RotateRight(root, parent);
        node = parent;
        parent = node->parent;
    }
    //Case 4a: red parent, no red uncle, and left imbalance about grandparent
    parent->color = true;
    grandparent->color = false;
    if (node == parent->left)
    {
        RotateRight(root, grandparent);
    }
    //Case 4b: red parent, no red uncle and right imbalance about grandparent
    else
    {
        RotateLeft(root, grandparent);
    }
}

void RedBlackTree::printingInorder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    printingInorder(node->left);
    //cout << node->severityIndex << " ";
    // if (node->color == false)
    // {
    //     cout << "red" << endl;
    // }
    // else
    // {
    //     cout << "black" << endl;
    // }
    treesize++;
    printingInorder(node->right);
}
/*****************************REFERENCES*********************/
/*Source: Introduction to Algorithms by Thomas H. Cormen
 Code:  RotateLeft and RotateRight Functions
 ************************************************************/
void RedBlackTree::RotateLeft(Node *root, Node *node)
{
    Node *newRoot = node->right;
    //setting the node's right subtree equal to newRoot's left subtree
    node->right = newRoot->left;
    //newRoot's left parent is node's parent
    if (newRoot->left != nullptr)
    {
        newRoot->left->parent = node;
    }
    newRoot->parent = node->parent;
    //if node does not have a parent, newRoot becomes the mainRoot of tree
    if (node->parent == nullptr)
    {
        mainRoot = newRoot;
    }
    //configuring the parent of node to print to newRoot
    else if (node == node->parent->left)
    {
        node->parent->left = newRoot;
    }
    else
    {
        node->parent->right = newRoot;
    }
    newRoot->left = node;
    node->parent = newRoot;
    return;
}

void RedBlackTree::RotateRight(Node *root, Node *node)
{
    Node *newRoot = node->left;
    //newRoot->parent = node->parent;
    node->left = newRoot->right;
    if (newRoot->right != nullptr)
    {
        newRoot->right->parent = node;
    }
    newRoot->parent = node->parent;
    if (node->parent == nullptr)
    {
        mainRoot = newRoot;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = newRoot;
    }
    else
    {
        node->parent->right = newRoot;
    }
    newRoot->right = node;
    node->parent = newRoot;
    return;
}

Node *RedBlackTree::getGrandparent(Node *node)
{
    return node->parent->parent;
}

Node *RedBlackTree::getUncle(Node *node)
{
    if (node->parent->parent->left == node->parent)
    {
        return node->parent->parent->right;
    }
    else
    {
        return node->parent->parent->left;
    }
}

Node *RedBlackTree::GetmostSevereAccident(Node *node)
{
    if (node->right == nullptr)
    {
        return node;
    }
    else
    {
        return GetmostSevereAccident(node->right);
    }
}

Node *RedBlackTree::GetleastSevereAccident(Node *node)
{
    if (node->left == nullptr)
    {
        return node;
    }
    else
    {
        return GetleastSevereAccident(node->left);
    }
}

void RedBlackTree::GetXmostSevereAccidents(Node *node, int &numAccidents, vector<Node *> &Accidents)
{
    if (numAccidents == 0) {
        return;
    }
    if (node == nullptr)
    {
        return;
    }
    GetXmostSevereAccidents(node->right, numAccidents, Accidents);

    if (numAccidents != 0)
    {
        Accidents.push_back(node);
        numAccidents--;
        
    }
    GetXmostSevereAccidents(node->left, numAccidents, Accidents);
}

void RedBlackTree::GetXleastSevereAccidents(Node *node, int &numAccidents, vector<Node *> &Accidents)
{
    if (node == nullptr)
    {
        return;
    }
    GetXleastSevereAccidents(node->left, numAccidents, Accidents);
    if (numAccidents != 0)
    {
        Accidents.push_back(node);
        numAccidents--;
    }
    GetXleastSevereAccidents(node->right, numAccidents, Accidents);
}

void RedBlackTree::GetXmostSevereCityAccidents(Node *node, int &numAccidents, string city, vector<Node *> &Accidents)
{
    if (node == nullptr)
    {
        return;
    }
    GetXmostSevereCityAccidents(node->right, numAccidents, city, Accidents);
    if (node->city == city)
    {
        if (numAccidents != 0)
        {
            Accidents.push_back(node);
            numAccidents--;
        }
    }
    GetXmostSevereCityAccidents(node->left, numAccidents, city, Accidents);
}
void RedBlackTree::GetXmostSevereStateAccidents(Node *node, int &numAccidents, string state, vector<Node *> &Accidents)
{
    if (node == nullptr)
    {
        return;
    }
    GetXmostSevereStateAccidents(node->right, numAccidents, state, Accidents);
    if (node->state == state)
    {
        if (numAccidents != 0)
        {
            Accidents.push_back(node);
            numAccidents--;
        }
    }
    GetXmostSevereStateAccidents(node->left, numAccidents, state, Accidents);
}

<<<<<<< HEAD
void RedBlackTree::GetXmostSevereAccidentsInYear(Node* node, int& numAccidents, int year, vector<Node*>& Accidents)
=======
void RedBlackTree::GetXmostSevereAccidentsInYear(Node *node, int &numAccidents, int year, vector<Node *> &Accidents)
>>>>>>> parent of c30659e (Changes made on 8/1)
{
    if (node == nullptr)
    {
        return;
    }
    GetXmostSevereAccidentsInYear(node->right, numAccidents, year, Accidents);
    if (node->year == year)
    {
        if (numAccidents != 0)
        {
            Accidents.push_back(node);
            numAccidents--;
        }
    }
    GetXmostSevereAccidentsInYear(node->left, numAccidents, year, Accidents);
<<<<<<< HEAD
}
=======
}
>>>>>>> parent of c30659e (Changes made on 8/1)
