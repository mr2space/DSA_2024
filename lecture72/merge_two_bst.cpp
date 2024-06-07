#include<iostream>
#include <vector>
using namespace std;


class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};



void inorderVector(TreeNode * root, vector<int>& in){
    if (root == NULL) return ;
    inorderVector(root->left, in);
    in.push_back(root->data);
    inorderVector(root->right, in);
}


void mergeArray(vector<int> in1, vector<int> in2, vector<int>& ans){
    int i = 0;
    int j = 0;
    int k = 0;
    while (i<in1.size() && j < in2.size()){
        if (in1[i] < in2[j]){
            ans[k] = in1[i];
            i++;
            k++;
        }else{
            ans[k] = in2[j];
            j++;
            k++;
        }
    }

    while (i < in1.size()){
        ans[k] = in1[i];
        k++;
        i++;
    }

    while (j < in2.size()){
        ans[k] = in2[j];
        k++;
        j++;
    }
}


TreeNode * inorderToBST(vector<int>& arr, int s, int e){
    if (s > e) return NULL;
    int mid = (s+e) / 2;
    TreeNode * root = new TreeNode(arr[mid]);
    root->left = inorderToBST(arr, s, mid-1);
    root->right = inorderToBST(arr, mid+1, e);
    return root;
}


vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> in1, in2;
    inorderVector(root1, in1);
    inorderVector(root2, in2);
    vector<int>ans(in1.size()+in2.size());
    mergeArray(in1, in2, ans);
    return ans;
}