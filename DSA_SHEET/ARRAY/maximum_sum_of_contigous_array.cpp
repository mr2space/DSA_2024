#include<iostream>
#include <vector>
using namespace std;



class Solution2 {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        long long maxi = arr[0];
        
        for(int i =0; i<n; i++){
            long long sum = 0;
            for(int j=i; j<n; j++){
                sum += arr[j];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};


class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        long long maxi = arr[0];
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            maxi = max(maxi, sum);
            if (sum < 0) sum = 0;
        }
        return maxi;
    }
};