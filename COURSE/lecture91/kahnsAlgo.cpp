#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<int> inorder(v);
    for(auto p:adj){
        for(auto k: p.second){
            inorder[k]++;
        }
    }

    queue<int> q;
    vector<int> ans;

    for(int i=0; i<v; i++){
        if (inorder[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto neigh:adj[front]){
            inorder[neigh]--;
            if (inorder[neigh] == 0) q.push(neigh);
        }
    }

    return ans;





}