#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class BinaryTreeNode
{
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

bool valid(BinaryTreeNode<int> * root, int min, int max){
    if (root == NULL) return true;
    if (root->data >= min && root->data <= max){
        bool left = valid(root->left, min, root->data);
        bool right = valid(root->right, root->data, max);
        return left && right;
    }
    return false;

}


bool validateBST(BinaryTreeNode<int> *root) {
    bool ans = valid(root, INT_MIN, INT_MAX);
    return ans;
}