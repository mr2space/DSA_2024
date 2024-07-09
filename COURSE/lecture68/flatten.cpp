#include<iostream>
#include<queue>
#include<stack>
#include<map>
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
    void flatten(Node *root)
    {
        Node * current = root;
        while(current != NULL){
            if (current->left == NULL){
                current = current->right;
            }else{
                Node * p = current->left;
                while( p->right != NULL ){
                    p = p->right;
                }
                p->right = current->right;
                current->right = current->left;
                current->left = NULL;
            }
            current = current->right;
        }
    }
};
