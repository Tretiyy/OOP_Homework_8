#include "TreeNode.h"

int main()
{
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    root->StartLCA();

    system("pause");

    return 0;
}
