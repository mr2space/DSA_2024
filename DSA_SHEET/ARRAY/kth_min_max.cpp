#include<iostream>
#include<queue>
using namespace std;




int kthSmallest(int arr[], int l, int r, int k){
    priority_queue<int>pq;
    for(int i=l; i<r; i++){
        if (pq.size()<k){
            pq.push(arr[i]);
        }else if (pq.top() > arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();

}