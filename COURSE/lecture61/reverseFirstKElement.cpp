#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;


class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> s;
        for(int i = 0; i < k; i++){
            s.push(q.front());
            q.pop();
        }
        q.push(-1);
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        while(q.front() != -1){
            q.push(q.front());
            q.pop();
        }
        q.pop();
        return q;
    };
};