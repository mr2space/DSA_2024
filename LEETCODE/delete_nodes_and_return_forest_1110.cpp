#include<iostream>
#include <vector>
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
    void construct_parent(TreeNode* root, map<int, TreeNode*> &parent){
        if (root == NULL){
            return ;
        }
        if (root->left != NULL)
            parent[root->left->val] = root;
        if (root->right != NULL)
            parent[root->right->val] = root;
        construct_parent(root->left, parent);
        construct_parent(root->right, parent);
    }
    bool isExist(vector<int> &to_delete, int value){
        for(auto ele:to_delete){
            if (ele == value) return true;
        }
        return false;
    }

    void postOrder(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>& ans, map<int, TreeNode*> &parent){
        if (root == NULL) return ;
        postOrder(root->left, to_delete, ans, parent);
        postOrder(root->right, to_delete, ans, parent);
        if (isExist(to_delete, root->val)){
            if (root->left != NULL){
                ans.push_back(root->left);
            }
            if (root->right != NULL){
                ans.push_back(root->right);
            }
            if (parent[root->val] != NULL){
                TreeNode * temp = parent[root->val];
                if (temp->left->val == root->val){
                    temp->left = NULL;
                }else{
                    temp->right = NULL;
                }
            }
        }
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        map<int, TreeNode*> parent;
        vector<TreeNode*> ans;
        parent[root->val] = NULL;
        construct_parent(root, parent);
        postOrder(root, to_delete, ans, parent);
        if (!isExist(to_delete, root->val)){
            ans.push_back(root);
        }
        return ans;
    }
};