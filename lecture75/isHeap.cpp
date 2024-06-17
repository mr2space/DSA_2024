#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int count(struct Node * tree){
        if (tree ==  NULL) return 0; 
        return count(tree->left)+count(tree->right)+1;
    }
    bool isCompleteBinaryTree(struct Node* tree, int idx, int totalNode){
        if (tree == NULL) return true;
        if (idx >= totalNode) return false;
        else{
            bool left = isCompleteBinaryTree(tree, 2*idx+1, totalNode);
            bool right = isCompleteBinaryTree(tree, 2*idx+2, totalNode);
            return (left && right);
        }
    }

    bool isMaxOrder(struct Node * tree){
        if (tree->left == NULL && tree->right == NULL) return true;
        if (tree->right == NULL) return (tree->data > tree->left->data);
        else{
            struct  Node* left = tree->left;
            struct  Node* right = tree->right;

            return (((tree->data > left->data) && (tree->data > right->data)) && (isMaxOrder(left) && isMaxOrder(right)));
        }
    }

    bool isHeap(struct Node* tree) {
        int idx = 0;
        int totalCount = count(tree);
        return isCompleteBinaryTree(tree, idx, totalCount) && isMaxOrder(tree);
    }
};