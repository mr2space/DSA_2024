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

   
class Solution
{
    public:
    //Function to check if two trees are identical.
        int height(Node* root) {
        if (!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return (left>right)?left+1:right+1;
    }

    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == NULL && r2 == NULL) return true;
        if(r1 == NULL || r2 == NULL) return false;
        if (r1->data == r2->data){
            return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
        }
        return false;

    }
};

