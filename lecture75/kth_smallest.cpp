#include<iostream>
#include <queue>
using namespace std;




class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;
        int i = 0;
        for(i = 0; i < k; i++){
            pq.push(arr[i]);
        }
        for(i; i <= r; i++){
            if (pq.top() > arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};