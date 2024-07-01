#include<iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <list>
#include <stack>
using namespace std;
void bfs(unordered_map<int,list<int>>& adjlist, unordered_map<int, bool>& visited, vector<int>& ans, int i){

    ans.push_back(i);
    visited[i] = true;
    for(auto j:adjlist[i]){
        if(!visited[j]){
            bfs(adjlist, visited, ans, j);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges){
    unordered_map<int,list<int>>adjlist;
    for(int i=0; i<edges.size(); i++){
        int v = edges[i][0];
        int u = edges[i][1];

        adjlist[v].push_back(u);
        adjlist[u].push_back(v);
    }
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    for(int i=0; i<V; i++){
        vector<int> comp;
        if(!visited[i]){
            bfs(adjlist,visited,comp,i);
        }
        ans.push_back(comp);
    }
    return ans;
}

