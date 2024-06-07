#include<iostream>
#include <climits>
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


class info{
    public:
    int maxi, mini;
    bool isBst;
    int size;
};

info solve(TreeNode * root, int& ans){
    if (root == NULL) {
        info temp;
        temp.maxi = INT_MIN;
        temp.mini = INT_MAX;
        temp.isBst = true;
        temp.size = 0;
        return temp;
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);
    info temp;
    temp.size = left.size + right.size + 1;
    temp.maxi = max(root->data, right.maxi);
    temp.mini = min(root->data, left.mini);
    if (left.isBst && right.isBst && (left.maxi < root->data && root->data < right.mini)){
        temp.isBst = true;
    }else{
        temp.isBst = false;
    }

    if (temp.isBst){
        ans = max(ans, temp.size);
    }
    return temp;
}

int largestBST(TreeNode * root){
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}