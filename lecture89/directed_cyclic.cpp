#include<iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;


bool isCycle(unordered_map<int, list<int>>&adj, unordered_map<int,bool>&visited,unordered_map<int, bool>&dfsvisisted, int node ){
    visited[node] = 1;
    dfsvisisted[node] = 1;

    for(auto neigh:adj[node]){
        if (!visited[neigh]){
            isCycle(adj, visited, dfsvisisted, neigh);
        }else if(dfsvisisted[neigh]){
            return true;
        }
    }
    dfsvisisted[node] = 0;
    return false;

}



int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, list<int>>adj;
    for(auto ele:edges){
        int v = ele.first;
        int u = ele.second;
        adj[v].push_back(u);
    }

    unordered_map<int,bool>visited;
    unordered_map<int, bool>dfsvisisted;

    for(int i=1; i<=n; i++){
        if (!visited[i]){
            if (isCycle(adj, visited, dfsvisisted, i)) return true;
        }
    }
    return false;
    
}