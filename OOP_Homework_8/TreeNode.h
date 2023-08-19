#pragma once
#include <vector>

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode(T val);
    TreeNode<T>* GetRandNode();
    void StartLCA();
    void LCA(TreeNode<T>* n1, TreeNode<T>* n2);
private:
    int CountNodes(TreeNode<T>* node);
    TreeNode<T>* GetNthNode(TreeNode<T>* node, int n);
    bool FindPathToNode(TreeNode<T>* current, TreeNode<T>* target, std::vector<TreeNode<T>*>& path);
};