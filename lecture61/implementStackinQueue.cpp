#include<iostream>
#include<queue>

using namespace std;



class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if (q.empty()){
            return -1;
        }
        q.push(-1);
        int x  = q.front();
        q.pop();
        while(q.front() != -1){
            q.push(x);
            x = q.front();
            q.pop();
        }
        q.pop();
        return x;
    }
    
    int top() {
        if (q.empty()){
            return -1;
        }
        q.push(-1);
        int x ;
        while(q.front() != -1){
            x = q.front();
            q.push(x);
            q.pop();
        }
        q.pop();
        return x;
    }
    
    bool empty() {
        if (q.empty()){
            return true;
        }else{
            return false;
        }
    }
};