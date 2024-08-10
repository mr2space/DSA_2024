#include<iostream>
#include <vector>
using namespace std;




class Solution {
  public:
    long long int solve(int a[], int N, int idx, int target, vector<vector<long long int>> &dp){
        if (idx == 0) return target % a[idx] == 0;

        if (dp[idx][target] != -1) return dp[idx][target];
        long long int notTake = solve(a, N, idx-1, target, dp);
        long long int take = 0;
        if (target - a[idx] >= 0) take = solve(a, N, idx, target-a[idx], dp);
        return dp[idx][target] = take + notTake;
    }

    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>> dp(N+1, vector<long long int>(sum+1, -1));
        return solve(coins, N, N-1, sum, dp);
    }
};