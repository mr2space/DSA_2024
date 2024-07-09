#include<iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

void dfs(int node, unordered_map<int,bool>& visited, stack<int>& s, unordered_map<int, list<int>>& adj){
    visited[node] = true;
    for(auto n:adj[node]){
        if (!visited[n]){
            dfs(n, visited, s, adj);
        }
    }
    s.push(node);
}


void revDfs(int node, unordered_map<int,bool>& visited, unordered_map<int,list<int>>&transpose){
    visited[node] = true;
    for(auto nbr:transpose[node]){
        if (!visited[nbr]){
            revDfs(nbr, visited, transpose);
        }
    }

}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges){

	unordered_map<int,list<int>>adjlist;
    unordered_map<int,list<int>>transpose;

    for(int i=0; i<edges.size(); i++){
        int v = edges[i][0];
        int u = edges[i][1];
        adjlist[v].push_back(u);
        transpose[u].push_back(v);
    }

    unordered_map<int,bool> visited;
    stack<int> st;

    for(int i=0; i<v; i++){
        if (!visited[i]){
            dfs(i,visited,st,adjlist);
        }
    }
    for(int i = 0; i < v; i++) {
        visited[i] = false;
    }
    int count = 0;
    while(!st.empty()){
        int ele = st.top();
        st.pop();
        if (!visited[ele]){
            count++;
            revDfs(ele, visited, transpose);
        }

    }
    return count;
}