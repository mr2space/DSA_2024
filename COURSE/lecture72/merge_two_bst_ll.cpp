#include<iostream>
#include<vector>
using namespace std;


class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

TreeNode * bstToSortedDLL(TreeNode * root, TreeNode * &head){
    if (root == NULL) return NULL;
    bstToSortedDLL(root->right, head);
    root->right = head;
    if (head != NULL) head->left = root;
    head = root;
    bstToSortedDLL(root->left, head);
}