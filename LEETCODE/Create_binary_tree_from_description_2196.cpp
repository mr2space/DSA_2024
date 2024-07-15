#include<iostream>
#include <vector>
#include <map>
#include <unordered_map>
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, int> parentMap;
        unordered_map<int, TreeNode*> mp;

        for(int i=0; i<descriptions.size(); i++){
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];
            if (mp.find(parent) == mp.end()){
                TreeNode * temp = new TreeNode(parent);
                mp[parent] = temp;
                parentMap[parent] = -1;
            }
            if (mp.find(child) == mp.end()){
                TreeNode * temp = new TreeNode(child);
                mp[child] = temp;
                parentMap[child] = -1;
            }

            if (isLeft){
                mp[parent]->left = mp[child];
            }else{
                mp[parent]->right = mp[child];
            }

            if (parentMap[parent] == -1){
                parentMap[child] = parent;
            }else{
                parentMap[child] = parentMap[parent];
            }


        }
        int ans = 0;
        for(auto ele:parentMap){
            if (ele.second == -1){
                return mp[ele.first];
            }
        }
        return mp[0];
    }
};