#include<iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
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
        if(left)
            delete left;
        if(right)
            delete right;
    }
};


void inorderVector(TreeNode<int>* root, vector<TreeNode<int> *>& in){
    if (root == NULL) return ;
    inorderVector(root->left, in);
    in.push_back(root);
    inorderVector(root->right, in);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<TreeNode<int> *> in;
    inorderVector(root, in);
    int i = 0;
    for(i=0; i < in.size()-1; i++){
        in[i]->left = NULL;
        in[i]->right = in[i+1];
    }
    in[i]->left = NULL;
    in[i]->right = NULL;
    return in[0];
}

