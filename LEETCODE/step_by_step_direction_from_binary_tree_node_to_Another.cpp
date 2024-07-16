#include<iostream>
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
    TreeNode * lca(TreeNode * root, int n1, int n2){
        if (root == NULL){
            return root;
        }

        if (root->val == n1 || root->val == n2){
            return root;
        }
        TreeNode * leftAns = lca(root->left, n1, n2);
        TreeNode * rightAns = lca(root->right, n1, n2);

        if (leftAns != NULL && rightAns != NULL){
            return root;
        }

        if (leftAns != NULL && rightAns == NULL){
            return leftAns;
        }

        if (leftAns == NULL && rightAns != NULL){
            return rightAns;
        }

        return NULL;


    };


    void getDirection(TreeNode* root, int val, string &temp, string &result){
        if (root == NULL) return ;
        if (root->val == val){
            result = temp;
        }
        temp.push_back('U');
        getDirection(root->left, val, temp, result);
        getDirection(root->right, val, temp, result);
        temp.pop_back();
    }

    void getDirectionRoot(TreeNode* root, int val , string &temp, string &result){
        if (root == NULL) return ;
        if (root->val == val){
            result += temp;
        }
        temp.push_back('L');
        getDirectionRoot(root->left, val, temp, result);
        temp.pop_back();
        temp.push_back('R');
        getDirectionRoot(root->right, val, temp, result);
        temp.pop_back();
    }


    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode * a = lca(root, startValue, destValue);
        string result = "";
        string temp = "";
        getDirection(a, startValue, temp, result);
        getDirectionRoot(a, destValue, temp, result);
        return result;
    }
};