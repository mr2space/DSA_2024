#include<iostream>
#include <vector>
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
    
};

void inorderVector(BinaryTreeNode<int>* root, vector<int>& in){
    if (root == NULL) return ;
    inorderVector(root->left, in);
    in.push_back(root->data);
    inorderVector(root->right, in);
}



bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> in;
    inorderVector(root, in);
    int i = 0;
    int j = in.size() -1 ;
    while (i < j){
        int temp = in[i] + in[j];
        if (temp == target){
            break;
        }
        if (temp < target){
            i++;
        }else{
            j--;
        }
    }

    if (i >= j) return false;
    return true;
}