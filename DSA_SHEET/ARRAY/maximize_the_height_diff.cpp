#include<iostream>
#include <climits>
using namespace std;

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr+n);
        int diff = arr[n-1] - arr[0];
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i=1; i<n; i++){
            if (arr[i]-k < 0 ) continue;
            maxi = max(arr[i-1]+k, arr[n-1]-k);
            mini = min(arr[i]-k, arr[0]+k);
            diff = min(diff, maxi-mini);
        }
        return diff;
        
    }
};
