#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    int i,j;
    node(int data, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
    bool operator()(node*a, node*b){
        return a->data > b->data;
    }
}



vector<int> mergeKsortedArrays(vector<vector<int>> &kArray, int k){
    priority_queue<node*, vector<node*>, compare> pq;
    vector<int> ans;
    for(int i=0; i < k; i++){
        node temp = new node(kArray[i][0], i, 0);
        pq.push(temp);
    }
    while(pq.size()>0){
        node * temp = pq.top();
        pq.pop();
        ans.push_back(temp->data);
        if (temp.j < kArray[temp->i].size()){
            temp = new node(kArray[temp.i][temp.j+1], temp.i, temp.j +1);
            pq.push(temp);
        }
    }
    return ans;
}
