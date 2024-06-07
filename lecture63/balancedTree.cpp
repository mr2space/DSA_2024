#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};




class Solution{
    bool result = true;
    public:
    //Function to check whether a binary tree is balanced or not.
    int height(Node* root) {
        if (!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        if (abs(left-right) > 1){
            result = false;
        }
        return (left>right)?left+1:right+1;
    }
    bool isBalanced(Node *root)
    {
       height(root);
       return result;
    }
};