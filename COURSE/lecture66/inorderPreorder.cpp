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


class Solution{
    public:
    int findPos(int arr[],int startidx, int size, int k){
        for(int i = startidx; i < size; i++){
            if (arr[i] == k){
                return i;
            }
        }
        return -1;
    }
    Node * build(int in[],int pre[], int& index, int inorderstart, int inorderEnd, int n){

        if (index >= n || inorderstart > inorderEnd){
            return NULL;
        }

        int ele = pre[index++];
        Node * root = new Node(ele);

        int pos = findPos(in,inorderstart, n, ele);

        root->left = build(in, pre, index,inorderstart, pos-1,n);
        root->right = build(in, pre, index,pos+1, inorderEnd,n);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int index = 0;
        return build(in, pre, index, 0, n-1,n);
    }
};

