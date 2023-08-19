#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>
TreeNode<T>::TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}

template <typename T>
TreeNode<T>* TreeNode<T>::GetRandNode() 
{
    int numNodes = CountNodes(this);
    int randIndex = rand() % numNodes;
    return GetNthNode(this, randIndex);
}

template <typename T>
void TreeNode<T>::StartLCA() 
{
    if (!left || !right)
    {
        cout << "The tree doesn't have enough nodes for LCA." << endl;
        return;
    }

    srand(time(NULL));
    TreeNode<T>* randNode1 = GetRandNode();
    TreeNode<T>* randNode2 = GetRandNode();

    cout << "Random Node 1: " << randNode1->data << endl;
    cout << "Random Node 2: " << randNode2->data << endl;

    LCA(randNode1, randNode2);
}

template <typename T>
void TreeNode<T>::LCA(TreeNode<T>* n1, TreeNode<T>* n2)
{
    if (!n1 || !n2) 
    {
        cout << "Invalid nodes provided." << endl;
        return;
    }

    if (n1 == n2)
    {
        cout << "LCA is " << n1->data << endl;
        return;
    }

    vector<TreeNode<T>*> pathToN1;
    vector<TreeNode<T>*> pathToN2;

    if (!FindPathToNode(this, n1, pathToN1) || !FindPathToNode(this, n2, pathToN2))
    {
        cout << "Nodes not found in the tree." << endl;
        return;
    }

    TreeNode<T>* lca = nullptr;
    int minLength = min(pathToN1.size(), pathToN2.size());

    for (int i = 0; i < minLength; ++i) 
    {
        if (pathToN1[i] == pathToN2[i])
            lca = pathToN1[i];
        else
            break;
    }

    if (!lca)
        cout << "No Common Ancestor found for " << n1->data << " and " << n2->data << endl;
    else
        cout << "Lowest Common Ancestor of " << n1->data << " and " << n2->data << " is " << lca->data << endl;
}


template <typename T>
int TreeNode<T>::CountNodes(TreeNode<T>* node)
{
    if (!node) 
        return 0;
    return 1 + CountNodes(node->left) + CountNodes(node->right);
}

template <typename T>
TreeNode<T>* TreeNode<T>::GetNthNode(TreeNode<T>* node, int n)
{
    if (!node)
        return nullptr;

    int leftCount = CountNodes(node->left);
    if (n < leftCount)
        return GetNthNode(node->left, n);
    else if (n == leftCount)
        return node;
    else
        return GetNthNode(node->right, n - leftCount - 1);
}

template <typename T>
bool TreeNode<T>::FindPathToNode(TreeNode<T>* current, TreeNode<T>* target, std::vector<TreeNode<T>*>& path) 
{
    if (!current)
        return false;

    path.push_back(current);

    if (current == target)
        return true;

    if ((current->left && FindPathToNode(current->left, target, path)) ||
        (current->right && FindPathToNode(current->right, target, path))) {
        return true;
    }

    path.pop_back();
    return false;
}

template class TreeNode<int>;