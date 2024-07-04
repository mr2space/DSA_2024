#include <bits/stdc++.h> 
#include <vector>

using namespace std;


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int, list<pair<int,int>>> adj;

    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];

        adj[u].push_back(make_pair(v,weight));
        adj[v].push_back(make_pair(u,weight));

    }


    set<pair<int,int>> s;
    vector<int>distance(vertices, INT_MAX);
    distance[source] = 0;
    s.insert(make_pair(0,0));

    while (!s.empty()){
        pair<int, int>top = *(s.begin());
        s.erase(top);
        for(auto neighbour:adj[top.second]){
            if (top.first + neighbour.second < distance[neighbour.first]){
                auto record = s.find(make_pair(distance[neighbour.first], neighbour.first));
                if (record != s.end()){
                    s.erase(record);
                }
                distance[neighbour.first] = top.first + neighbour.second;
                s.insert(make_pair(distance[neighbour.first], neighbour.first));
            }
        }

    }
    return distance;

}
