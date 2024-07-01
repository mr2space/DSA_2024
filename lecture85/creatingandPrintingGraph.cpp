#include<iostream>
#include <vector>
using namespace std;

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    
    vector<int>ans[n];
    for(int i=0; i<edges.size(); i++){
        int v = edges[i][0];
        int u = edges[i][1];

        ans[v].push_back(u);
        ans[u].push_back(v);
    }

    vector<vector<int>> adj(n);
    for(int i=0; i<n; i++){
        adj[i].push_back(i);
        for(int j=0; j<ans[i].size(); j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}