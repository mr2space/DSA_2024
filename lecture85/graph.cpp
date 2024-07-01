#include<iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>>adj;
    void insert(int u, int v, bool directed){
        // directed = 1 -> directed graph
        adj[u].push_back(v);
        if(directed == 0){
            adj[v].push_back(u);
        }
    }

    void printGraph(){
        for(auto i:adj){
            cout << i.first << "->";
            for(auto j:i.second){
                cout << j << " ";
            }
            cout << endl;
        }
    }
    
};


int main(){
    Graph g;
    g.insert(0,1,0);
    g.insert(1,2,0);
    g.insert(2,3,0);
    g.insert(3,4,0);
    g.insert(3,1,0);
    g.insert(4,0,0);

    g.printGraph();
    return 0;
}

