#include <bits/stdc++.h> 

using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
    unordered_map<int, vector<pair<int, int>>> adj;
    for(int i=0; i<m; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> key(n+1, INT_MAX);
    vector<int> parent(n+1, -1);
    vector<int> mst(n+1, 0);

    key[1] = 0;

    for(int i=1; i<=n; i++){

        int mini = INT_MAX;
        int u;

        for(int v=1; v<=n; v++){
            if (mst[v] == 0 && (key[v] < mini)){
                mini = key[v];
                u =  v;
            }
        }

        mst[u] = 1;

        for(auto neighbour:adj[u]){
            if (mst[neighbour.first] == 0 && (neighbour.second < key[neighbour.first])){
                key[neighbour.first] = neighbour.second ;
                parent[neighbour.first] = u;
            }
        }

    }
    
    vector<pair<pair<int, int>,int>> result;
    for(int i=2; i<=n; i++){
        result.push_back({{parent[i],i},key[i]});
    }
    return result;

}
