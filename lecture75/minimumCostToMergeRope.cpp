#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for(long long i = 0; i < n; i++){
            minHeap.push(arr[i]);
        }
        long long cost = 0;
        while(minHeap.size() > 1){
            long long sum = 0;
            sum = minHeap.top();
            minHeap.pop();
            sum += minHeap.top();
            minHeap.pop();
            minHeap.push(sum);
            cost += sum;
        }
        return cost;
    }
};



