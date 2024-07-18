#include<iostream>
#include <map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    map<TreeNode*, int> postOrder(TreeNode* root, int &distance, int &ans){
        if (root == NULL) return {};
        if (root->left == NULL && root->right == NULL){
            map<TreeNode*, int> temp;
            temp[root] = 1;
            return temp;
        }
        map<TreeNode*, int> left_node = postOrder(root->left, distance, ans);
        map<TreeNode*, int> right_node = postOrder(root->right, distance, ans);
        map<TreeNode*, int> temp;
        for(auto left:left_node){
            for(auto right:right_node){
                if (left.second + right.second <= distance){
                    ans++;
                }
            }
        }
        for(auto left:left_node){
            if (left.second + 1 <= distance)
                temp[left.first] = left.second + 1;
        }
        for(auto right:right_node){
            if (right.second +1 <= distance)
                temp[right.first] = right.second + 1;
        }
        return temp;
    }

    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        postOrder(root, distance, ans);
        return ans;
    }
};