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

TreeNode * search(TreeNode * root, int target, TreeNode* &pre, TreeNode* &suc){
    if (root == NULL) return NULL;
    if (root->data == target){
        return root;
    }
    if (root->data > target){
        suc = root;
        return search(root->left, target, pre, suc);
    }

    if (root->data < target){
        pre = root;
        return search(root->right, target, pre, suc);
    }

}


TreeNode * minimum(TreeNode * target){
    if (target == NULL || target->left == NULL) return NULL;
    target = target->left;
    while(target->right != NULL){
        target = target->right;
    }
    return target;
}

TreeNode * maximum(TreeNode * target){
    if (target == NULL || target->right == NULL) return NULL;
    target = target->right;
    while(target->left != NULL){
        target = target->left;
    }
    return target;
}







pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    TreeNode * successor = new TreeNode(-1),  * predecessor = new TreeNode(-1);
    TreeNode * target = search(root, key, predecessor, successor);
    TreeNode * temp = minimum(target);
    predecessor = (temp)?temp:predecessor;
    temp = maximum(target);
    successor = (temp)?temp:successor;
    pair<int, int> ans = make_pair(predecessor->data, successor->data);
    return ans;
}