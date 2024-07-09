#include <iostream>
#include <queue>

using namespace std;

class Deque
{
    int *arr;
    int size;
    int front, rear;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        arr = new int[n];
        size = n;
        front = rear = -1;
    }
    void print(){
        cout << "-";
        for(int i = front; i<=rear; i = (i+1)%size){
            cout << front << " ";
        }
        cout << endl;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if (rear == (front-1)%size){
            return false;
        }
        if (front == -1){
            rear = 0;
            front = 0;
            arr[front] = x;
            return true;
        }
        if (front-1 < 0){
            front = size-1;
        }else{
            front--;
        }
        front = front%size;
        arr[front] = x;
        cout << x;
        print();
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if (front == (rear+1)%size){
            return false;
        }
        if (front == -1){
            rear = front = 0;
            arr[rear] = x;
            return true;
        }
        rear = (rear + 1)%size;
        arr[rear] = x;
        cout << x;
        print();
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if (front == -1){
            return -1;
        }
        int temp = arr[front];
        if (front == rear){
            front = rear = -1;
            return temp;
        }
        front = (front + 1)%size;
        // cout << x;
        print();
        return temp;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if (front == -1){
            return -1;
        }
        int temp = arr[front];
        if (front == rear){
            front = rear = -1;
            return temp;
        }
        if (rear-1 < 0){
            rear = size-1;
        }else{
            rear--;
        }
        rear = rear % size;
        return temp;
        // cout << x;
        print();
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (front == -1) return -1;
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (front == -1) return -1;
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (front == -1) return true;
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if ((front == (rear+1)%size)){
            return true;
        }
        return false;
    }
};