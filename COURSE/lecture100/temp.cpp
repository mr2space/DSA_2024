#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

void dfs(int node, unordered_map<int,bool>& visited, stack<int>& s, unordered_map<int, list<int>>& adj) {
    visited[node] = true;
    for(auto n : adj[node]) {
        if (!visited[n]) {
            dfs(n, visited, s, adj);
        }
    }
    s.push(node);
}

void revDfs(int node, unordered_map<int,bool>& visited, unordered_map<int,list<int>>& transpose) {
    visited[node] = true;
    for(auto nbr : transpose[node]) {
        if (!visited[nbr]) {
            revDfs(nbr, visited, transpose);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>>& edges) {
    unordered_map<int,list<int>> adjlist;
    unordered_map<int,list<int>> transpose;

    // Build the adjacency list and transpose
    for(int i = 0; i < edges.size(); i++) {
        int v = edges[i][0];
        int u = edges[i][1];
        adjlist[v].push_back(u);    // Original graph
        transpose[u].push_back(v);  // Transposed graph
    }

    unordered_map<int,bool> visited;
    stack<int> st;

    // Perform DFS and fill stack 'st' with nodes in order of finish time
    for(int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, visited, st, adjlist);
        }
    }

    // Reset visited for second DFS
    for(int i = 0; i < v; i++) {
        visited[i] = false;
    }

    int count = 0;
    // Process nodes in stack order and perform DFS on transpose graph
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            count++;
            revDfs(node, visited, transpose);
        }
    }

    return count;
}

int main() {
    // Example usage
    int vertices = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 2}};
    int sccCount = stronglyConnectedComponents(vertices, edges);
    cout << "Number of Strongly Connected Components: " << sccCount << endl;
    return 0;
}
