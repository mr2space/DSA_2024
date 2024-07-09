#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;

struct node{
    int data, i, j;
    node(int data, int i, int j){
        this->data = data;
        this->i = i;
        this->j = j;
    }
};


class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};


int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_MAX, maxi = INT_MIN;   
    priority_queue<node*, vector<node*>, compare> pq;

    for(int i = 0; i < a.size(); i++){
        mini = min(mini, a[i][0]);
        maxi = max(maxi, a[i][0]);
        pq.push(new node(a[i][0], i, 0));
    }

    int start = mini;
    int end = maxi;

    while(!pq.empty()){
        node * temp = pq.top();
        pq.pop();
        mini = temp->data;
        if ((maxi - mini) < (end-start)){
            end = maxi;
            start = mini;
        }
        if(temp->j < a[temp->i].size()){
            maxi = max(maxi, a[temp->i][temp->j+1]);
            pq.push(new node(a[temp->i][temp->j+1], temp->i, temp->j+1 ));
        }
    }

    return (end - start + 1);

}