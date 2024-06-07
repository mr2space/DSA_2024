#include <bits/stdc++.h> 
class CircularQueue{
    int * arr;
    int size;
    int front, rear;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        arr = new int[n];
        size = n;
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // if queue is full
        if (front == (rear + 1)%size){
            return false;
        }
        // cout << value << "-" << endl;
        // first push
        if (front == -1){
            front = 0;
            rear = 0;
            arr[rear] = value;
            return true;
        }
        rear =  (rear + 1)%size;
        arr[rear] = value;
        return true;

    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if (front == -1){
            return -1;
        }
        int temp = arr[front];
        arr[front]=-1;
        if (front == rear){
            front = rear = -1;
            return temp;
        }
        // cout << temp << "@" << endl;
        front = (front+1)%size;
        return temp;
    }
};