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
        sum = 0;
        for(int j = i; j < arr.size(); j++){
            sum += arr[j];
            sumarr.push_back(sum);
            if (pq.size()<=k){
                pq.push(sum);
            }
        }
    }
    cout << endl;

    for(int i = k; i < sumarr.size(); i++){
        if (pq.top() < sumarr[i]){
            pq.pop();
            pq.push(sumarr[i]);
        }
    }
    return pq.top();
}

int main(){
    vector<int> input = {3 ,-2 ,5};
    int k = 3;
    cout << getKthLargest(input, k) << endl;
    return 0;
}