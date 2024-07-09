#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

void setInit(vector<int>& parent, vector<int>& rank, int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }

}   

int findParent(int node, vector<int>& parent){
    if (parent[node] != node) {
        parent[node] = findParent(parent[node], parent); // Path compression
    }
    return parent[node];
}


void unionSet(int u, int v, vector<int>& parent, vector<int>& rank){
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] < rank[v]){
        parent[u] = v;
    }else if (rank[u] > rank[v]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rank[u]++;
    }

}

bool cmp(vector<int> edge1, vector<int> edge2){
    return edge1[2] < edge2[2];
}




int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    vector<int> parent(n);
    vector<int> rank(n);
    setInit(parent, rank,n);
    sort(edges.begin(), edges.end(), cmp);
    int minWeight =0;
    for(int i=0; i<edges.size(); i++){
        int u = findParent(edges[i][0], parent);
        int v = findParent(edges[i][1], parent);

        if (u != v){
            minWeight += edges[i][2];
            unionSet(u,v,parent,rank);
        }

    }
    return minWeight;

}