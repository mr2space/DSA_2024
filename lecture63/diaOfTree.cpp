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


class Solution {
    int max = 0;
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node* root) {
        if (!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        int dia = 1 + left + right;
        max = (max > dia)?max:dia;
        return (left>right)?left+1:right+1;
    }
    int diameter(Node * root){
        height(root);
        return max;
    }
};
