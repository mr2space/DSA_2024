#include <bits/stdc++.h>
#include <vector>
using namespace std;



void dfs(int node, vector<bool>& visited, stack<int>& s, unordered_map<int, vector<pair<int, int>>>&adj){
    visited[node] = 1;
    for(auto n:adj[node]){
        if (!visited[n.first]){
            dfs(n.first, visited, s, adj);
        }
    }
    s.push(node);
}

vector<int> ShortestDAG(vector<vector<pair<int,int>>> &edges, int v, int e, int source) {
    //converting to adj list 
    unordered_map<int, vector<pair<int, int>>>adj; // weight adj eg->  1 -> [2,-1] [3,8]
    for(int i=0; i<e; i++){
        pair<int,int> u = edges[i][0];
        pair<int,int> v = edges[i][1];
        adj[u.first].push_back(v);
    }
    vector<bool> visited(v);
    stack<int> s;
    // preparing topological sort and ans in stack
    for(int i=0; i<v; i++){
        if (!visited[i]){
            dfs(i,visited,s,adj);
        }
    }
    //distance vector
    vector<int> distance(adj.size(), INT_MAX);

    distance[source] = 0;
    int top = s.top();

    while(!s.empty()){
        top = s.top();
        s.pop();
        if (distance[top] == INT_MAX){continue;}
        for(auto neighbour:adj[top]){
            if (distance[top]+neighbour.second<distance[neighbour.first]){
                distance[neighbour.first] = distance[top]+neighbour.second;
            }
        }
    }
    return distance;
};