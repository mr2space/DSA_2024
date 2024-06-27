#include<iostream>
#include<vector>
#include <queue>
using namespace std;


//unchecked ----

int getKthLargest(vector<int> &arr, int k)
{

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> sumarr;


    int sum = 0;
	for(int i = 0; i < arr.size(); i++){
        sum = arr[i];
        for(int j = i+1; j < arr.size(); j++){
            sum += arr[j];
            sumarr.push_back(sum);
            if (pq.size()<=k){
                pq.push(sum);
            }
        }
    }

    for(int i = k+1; i < sumarr.size(); i++){
        if (pq.top() < sumarr[i]){
            pq.pop();
            pq.push(sumarr[i]);
        }
    }
    return pq.top();
}