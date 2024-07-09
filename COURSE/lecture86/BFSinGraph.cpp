#include<iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <list>
using namespace std;



void bfs(unordered_map<int,list<int>>& adjlist, unordered_map<int, bool>& visited, vector<int>& ans, int i){
    queue<int> q;
    q.push(i);

    while(!q.empty()){
        int front = q.front();
        ans.push_back(front);
        q.pop();
        visited[i] = true;

        for(auto j:adjlist[i]){
            if(!visited[j]) q.push(j);
        }
    }
}


vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    unordered_map<int,list<int>>adjlist;
    for(int i=0; i<adj.size(); i++){
        int v = adj[i][0];
        int u = adj[i][1];

        adjlist[v].push_back(u);
        adjlist[u].push_back(v);
    }


        for(auto i:adjlist){
            cout << i.first << "->";
            for(auto j:i.second){
                cout << j << " ";
            }
            cout << endl;
        }
    vector<int> ans;
    unordered_map<int, bool> visited;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bfs(adjlist,visited,ans,i);
        }
    }

    return ans;



}

