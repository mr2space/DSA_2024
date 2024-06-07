#include<iostream>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left){
            delete left;
        }
        if (right){
            delete right;
        }
    }
};

BinaryTreeNode<int> * solve(vector<int> &preorder, int& i , int mini, int maxi){
    if (i >= preorder.size()) return NULL;
    if (preorder[i] < mini || preorder[i] > maxi){
        return NULL;
    }
    BinaryTreeNode<int> * node = new BinaryTreeNode<int>(preorder[i++]);
    node->left = solve(preorder, i, mini, node->data);
    node->right = solve(preorder, i, node->data, maxi);
    return node;
}


BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int i = 0;
   return solve(preorder, i, INT_MIN, INT_MAX);
}
