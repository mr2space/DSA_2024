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

int ans;

Node * solve(Node* root, int k, int node){
    if (root == NULL) return NULL;
    if (root->data == node){
        return root;
    }
    Node * leftAns = solve(root->left, k, node);
    Node * rightAns = solve(root->right, k, node);

    if (leftAns != NULL && rightAns == NULL){
        k--;
        if (k <= 0){
            k = INT8_MAX;
            return root;
        }
    }

    if (rightAns != NULL && leftAns == NULL){
        k--;
        if (k <= 0){
            k = INT8_MAX;
            return root;
        }
    }

}


int kthAncestor(Node *root, int k, int node)
{
    Node * ans = solve(root, k, node);
    if (ans == NULL || ans->data == node){
        return -1;
    }
    return ans->data;
}