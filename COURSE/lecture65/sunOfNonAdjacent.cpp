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
    pair<int, int> solve(Node * root){
        if (root == NULL) return make_pair(0,0);
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        pair<int, int> res;
        res.first = root->data+left.second+right.second;
        res.second = max(left.first, left.second) + max(right.first, right.second);
        return res;
    }
    int getMaxSum(Node *root) 
    {
        pair<int , int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};

