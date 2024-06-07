#include<iostream>
#include<vector>

using namespace std;

class Queue{
    int * arr;
    int * next;
    int size;
    int *front, *rear;
    int freespot;
    public:
    Queue(int n,int size){
        this->size = size;
        next = new int[size];
        arr = new int[size];
        front = new int[n];
        rear = new int[n];
        for(int i = 0; i < n ; i++){
            front[i] = -1;
            rear[i] = -1;
        }
        for(int i = 0; i < size; i++){
            next[i] = i + 1;
        }
        next[size-1] = -1;
        freespot = 0;
    };
    void push(int k, int x){
        if (freespot == -1){
            return ;
        }
        int index = freespot;
        freespot = next[index];
        if (front[k-1] == -1){
            front[k-1] = index;
            rear[k-1] = index;
            arr[index] = x;
        }else{
            next[rear[k-1]] = index;
            rear[k-1] = index;
            next[index] = -1;
            arr[index] = x;
        }
    };
    int pop(int k){
        if (front[k-1] == -1){
            return -1;
        }
        int temp = arr[front[k-1]];
        front[k-1] = next[front[k-1]];
        return temp;
    };
};


int main(int argc, char const *argv[])
{
    Queue q(3, 9);
    q.push(1, 2);
    q.push(1,3);
    q.push(2,8);
    q.push(1,4);

    cout << q.pop(1) << endl;
    cout << q.pop(1) << endl;
    cout << q.pop(1) << endl;
    return 0;
}
