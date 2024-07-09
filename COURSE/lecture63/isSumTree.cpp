#include<iostream>

using namespace std;


struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution
{
    bool result = true;
    public:
    int calcSum(Node * root){
        if (!root) return 0;
        if (root->left == NULL && root->right == NULL) return root->data;
        int left = calcSum(root->left);
        int right = calcSum(root->right);
        if (root->data != (left + right)){
            result = false;
        }
        return root->data + right + left;
    }
    bool isSumTree(Node* root)
    {
        if (!root) return true;
        calcSum(root);
        return result;
    }
};
