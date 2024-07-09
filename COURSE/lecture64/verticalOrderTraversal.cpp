#include<iostream>
#include<bits/stdc++.h>
#include <vector>

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
    vector<int> verticalOrder(Node * root){
        map<int, map<int, vector<int>>> node;
        queue<pair<Node*, pair<int, int>>> q;
        vector<int> ans;
        q.push(make_pair(root, make_pair(0,0)));

        while(!q.empty()){
            pair<Node*, pair<int, int>> temp = q.front();
            q.pop();
            int hd = temp.second.first;
            int lv = temp.second.second;
            Node * r = temp.first;
            node[hd][lv].push_back(r->data);

            if (r->left){
                q.push(make_pair(r->left, make_pair(hd-1,lv+1)));
            }

            if (r->right){
                q.push(make_pair(r->right, make_pair(hd+1,lv+1)));
            }
        }

        for(auto& i:node){
            for(auto& j:i.second){
                for(auto& k:j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};

