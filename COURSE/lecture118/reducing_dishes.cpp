#include<iostream>
#include <vector>
using namespace std;




class Solution {
public:
    int solve(vector<int>& satisfaction, int idx, int time, vector<vector<int>> &dp){
        int n = satisfaction.size();
        if (idx == n) return 0;
        if ( dp[idx][time] != -1) return  dp[idx][time];
        int include = satisfaction[idx] * (time+1) + solve(satisfaction, idx+1, time+1, dp);
        int exclude = 0 + solve(satisfaction, idx+1, time, dp);
        dp[idx][time] = max(include, exclude);
        return  dp[idx][time];
    }
    int solveTab(vector<int>& satisfaction){
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int idx = n-1; idx >= 0; idx--){
            for(int time = n-1; time >= 0; time--){
                int include = satisfaction[idx] * (time+1) + dp[idx+1][time+1];
                int exclude = 0 + dp[idx+1][time];
                dp[idx][time] = max(include, exclude);
            }
        }
        return dp[0][0];

    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solveTab(satisfaction);

    }
};