#include<iostream>
#include<vector>
#include<map>
#include <queue>


using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};



class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        map<int, int> nodes;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            Node * r = temp.first;
            int h = temp.second;
            q.pop();
            if(nodes.find(h) == nodes.end()){
                nodes[h] = r->data;
            }
            if (r->left) q.push(make_pair(r->left,h+1));
            if (r->right) q.push(make_pair(r->right,h+1));
            
        }

        for(auto& i:nodes){
            ans.push_back(i.second);
        }
        return ans;
    }

    void Rec(Node * root,vector<int>& ans, int height){
        if (root == NULL) return;
        if (height == ans.size())
            ans.push_back(root->data);
        Rec(root->left, ans, height+1);
        Rec(root->right, ans, height+1);
    }
};