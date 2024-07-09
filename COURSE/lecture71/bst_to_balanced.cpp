#include<iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};


void inorderVector(TreeNode<int>* root, vector<int>& in){
    if (root == NULL) return ;
    inorderVector(root->left, in);
    in.push_back(root->data);
    inorderVector(root->right, in);
}

TreeNode<int> * inorderToBBST(int s, int e, vector<int>& in){
    if (s > e) return NULL;
    int mid = (s+e)/2;
    TreeNode<int> * root = new TreeNode<int>(in[mid]);
    root->left = inorderToBBST(s, mid-1, in);
    root->right = inorderToBBST(mid+1, e, in);
    return root;
}


TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> in;
    inorderVector(root, in);
    return inorderToBBST(0, in.size()-1, in);
}