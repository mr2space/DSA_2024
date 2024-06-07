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

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int, int> nodes;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            if(nodes.find(temp.second) == nodes.end()){
                nodes[temp.second] = temp.first->data;
            }
            if (temp.first->left) q.push(make_pair(temp.first->left,temp.second-1));
            if (temp.first->right) q.push(make_pair(temp.first->right,temp.second+1));
            
        }

        for(auto& i:nodes){
            ans.push_back(i.second);
        }
        return ans;
    }

};


