#include<iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int solve(int idx, int endidx,vector<int>& slices, int n, vector<vector<int>> &dp){
        if (n == 0 || idx > endidx){
            return 0;
        }
        if (dp[idx][n] != -1) return dp[idx][n];
        int take = slices[idx] + solve(idx+2, endidx, slices, n-1, dp);
        int not_take = 0 + solve(idx+1, endidx, slices, n, dp);
        dp[idx][n] = max(take, not_take);
        return dp[idx][n];

    }
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        int case1 = solve(0, n-2, slices, n/3, dp1);
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        int case2 = solve(1, n-1, slices, n/3, dp2);
        return max(case1, case2);
    }
};