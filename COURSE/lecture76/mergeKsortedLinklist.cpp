#include<iostream>
#include <vector>
#include<queue>
using namespace std;


class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};



class compare{
    public:
    bool operator()(Node*a, Node*b){
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<Node*, vector<Node*>, compare> pq;
    Node * ans = new Node(-1);
    Node * tail = ans;
    for(int i = 0; i < listArray.size(); i++){
        pq.push(listArray[i]);
    }

    while(!pq.empty()){
        tail->next = pq.top();
        tail = tail->next;
        pq.pop();
        if (tail->next){
            pq.push(tail->next);
        }
    }

    return ans->next;


}