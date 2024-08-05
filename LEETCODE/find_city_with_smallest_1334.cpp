#include<iostream>
#include <vector>
#include <set>
#include <climits>
#include <unordered_map>
#include <list>
using namespace std;



class Solution {
public:
    
    vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i=0; i<vec.size(); i++){
            int u = vec[i][0];
            int v = vec[i][1];
            int w = vec[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u, w});
        }

        set<pair<int, int>> s;
        vector<int> distance(vertices, INT_MAX);
        distance[source] = 0;
        s.insert({0, source});
        while(!s.empty()){
            pair<int, int> top = *(s.begin());
            s.erase(top);
            for(auto neighbour:adj[top.second]){
                if (top.first + neighbour.second < distance[neighbour.first]){
                    auto a = s.find({distance[neighbour.first], neighbour.second});
                    if (a != s.end()){
                        s.erase(a);
                    }
                    distance[neighbour.first] = (top.first + neighbour.second);
                    s.insert({distance[neighbour.first], neighbour.first});
                }
            }
        }
        return distance;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int ans = INT_MAX;
        int city_name = INT_MIN;
        for(int i=0; i<n; i++){
            vector<int> distance = dijkstra(edges, n, edges.size(), i);
            int curr_city_count = 0;
            for(int j=0; j<distance.size(); j++){
                if (i == j) continue;
                if (distance[j] <= distanceThreshold){
                    curr_city_count++;
                }
            }
            if (curr_city_count < ans){
                ans = curr_city_count;
                city_name = i;
            }else if(curr_city_count == ans && city_name < i){
                city_name = i;
            }
        }
        return city_name;
    }
};