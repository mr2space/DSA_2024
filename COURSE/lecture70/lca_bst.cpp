#include<iostream>
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

void solve(TreeNode * root, int a, int b, TreeNode * &ans){
    if (root == NULL){
        return ;
    }
    int temp = root->data;
    if (temp > a && temp > b){
        return solve(root->left, a, b, ans);
    }
    if (temp < a && temp < b){
         return solve(root->right, a, b, ans);
    }
    ans = root;
    return ;
}

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    TreeNode * ans = NULL;
    solve(root, P->data, Q->data, ans);
    return ans;
}