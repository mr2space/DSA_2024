#include<iostream>
#include<queue>
#include<stack>

using namespace std;
class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
    Node(){
        data = 0;
        left = right = NULL;
    }
};





class Solution
{
    public:
    Node * ans;

    Node * inorder(Node* root, int n1, int n2){
        if (root == NULL) return root;
        bool flagNode = false;
        if (root->data == n1 || root->data == n2){
            flagNode = true;
        }
        Node * left = inorder(root->left, n1, n2);
        Node * right = inorder(root->right, n1, n2);
        bool flagLeft = false;
        bool flagRight = false;
        if (left && (left->data == n1 || left->data == n2)){
            flagLeft = true;
        }
        if (right && (right->data == n1 || right->data == n2)){
            flagRight = true;
        }
        if (flagLeft && flagRight){
            ans = root;
            return NULL;
        }
        if (flagNode && flagLeft){
            ans = root;
            return NULL;
        }
        if (flagNode && flagRight){
            ans = root;
            return NULL;
        }
        if (flagLeft){
            return left;
        }
        if (flagRight){
            return right;
        }
        if (flagNode){
            return root;
        }
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       inorder(root, n1, n2);
       return ans;
    }
};