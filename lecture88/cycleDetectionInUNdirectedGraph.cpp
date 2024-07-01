#include<iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

bool isCycle(unordered_map<int, list<int>>& adj,unordered_map<int, bool>& visited, int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;
    unordered_map<int,int> parent;
    parent[node] = -1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neigh:adj[front]){
            if (visited[neigh] && parent[front] != neigh){
                return true;
            }else if(!visited[neigh]){
                q.push(neigh);
                visited[neigh] = 1;
                parent[neigh] = front;
            }
        }
    }
    return false;


}


string cycleDetection (vector<vector<int>>& edges, int n, int m){
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    for(int i=0; i<n; i++){
        if (!visited[i]){
            if (isCycle(adj, visited, i)) return "Yes";
        }
    }
    return "No";

}

