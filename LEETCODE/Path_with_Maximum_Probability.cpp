#include<iostream>
#include<limits>
#include <vector>
#include <unordered_map>
#include <list>
#include <set>
#include <cfloat>
#include <math.h>
using namespace std;


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, list<pair<int, double>>> adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double weight = succProb[i];
            adj[u].push_back({v, log(weight)});
            adj[v].push_back({u, log(weight)});
        }

        set<pair<double, int>, greater<>> s;
        vector<double>  distance(n, -numeric_limits<double>::infinity());
        distance[start_node] = 0;
        s.insert({0, start_node});

        while (!s.empty()){
            pair<double, int> top = *(s.begin());
            s.erase(top);

            for(auto neighbour: adj[top.second]){
                if (top.first + neighbour.second > distance[neighbour.first]){
                    auto rec = s.find({neighbour.second, neighbour.first});
                    if (rec != s.end()){
                        s.erase(rec);
                    }
                    distance[neighbour.first] = top.first + neighbour.second;
                    s.insert({top.first + neighbour.second, neighbour.first});
                }
            }
        }
        return distance[end_node] == -numeric_limits<double>::infinity() ? 0 : exp(distance[end_node]);
    }
};