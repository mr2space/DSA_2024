#include<iostream>
#include<queue>
#include<stack>
#include<map>
using namespace std;
class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
    Node(){
        data = 0;
        left = right = NULL;
    }
};


class Solution {
  public:
    map<Node*, Node*>parent;
    int time = 0;
    Node * TargetNode = NULL;

    void mapping(Node * root, Node * p, int target){
        if (root == NULL) return ;
        parent[root] = p;
        if (root->data == target) TargetNode = root;
        if (root->left) mapping(root->left, root, target);
        if (root->right) mapping(root->right, root, target);
    };

    int calcTime(Node * target){
        map<Node*, bool> visited;
        queue<Node *> q;
        q.push(target);
        visited[target] = true;
        
        while(!q.empty()){
            int size = q.size();
            bool flag = 0;
            for(int i = 0; i < size; i++){
                Node * temp = q.front();
                q.pop();
                if (temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    flag = true;
                    visited[temp->left] = true;
                }

                if (temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    flag = true;
                    visited[temp->right] = true;
                }

                if (parent[temp] && !visited[parent[temp]]){
                    q.push(parent[temp]);
                    flag = true;
                    visited[parent[temp]] = true;
                }
            }
            if (flag == 1){
                time++;
            }
        }
        return time;
    }

    int minTime(Node* root, int target) 
    {
        mapping(root, NULL, target);
        calcTime(TargetNode);
        return time - 1 ;
    }
};