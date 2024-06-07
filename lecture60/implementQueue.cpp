#include <bits/stdc++.h> 
class Queue {
    int * arr;
    int ft, rear;
    int size = 5000;
public:
    Queue() {
        arr = new int[5000];
        ft = -1;
        rear = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if (rear == -1) return true;
        return false;

    }

    void enqueue(int data) {
        if ((rear+1) == size){
            return ;
        }
        if (isEmpty()){
            rear = 0;
            ft = 0;
            // cout<<"--" << data << "--" <<endl;
            arr[rear] = data;
            return ;
        }
        // cout << data << "-" <<endl;
        arr[++rear] = data;
    }

    int dequeue() {
        if (isEmpty()){
            return -1;
        }
        int temp = arr[ft];
        if (ft == rear){
            ft = -1;
            rear = -1;
        }else{
            ft++;
        }

        return temp;
    }

    int front() {
        if (isEmpty()){
            return -1;
        }
        return arr[ft];
    }
};