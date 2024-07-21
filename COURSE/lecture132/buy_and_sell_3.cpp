#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(int idx, int buy,int limit, vector<int>& prices,  vector<vector<vector<int>>>& dp){
        if (idx == prices.size()) return 0;
        if (limit == 0) return 0;
        int profit = 0;
        if (dp[idx][buy][limit] != -1) return dp[idx][buy][limit];
        if (buy){
            profit =  -prices[idx] + solve(idx+1, 0,limit, prices, dp);
            profit = max(profit, 0 + solve(idx+1, 1,limit, prices, dp));
        }else{
            profit =  prices[idx] + solve(idx+1, 1,limit-1, prices, dp);
            profit = max(profit, 0 + solve(idx+1, 0,limit, prices, dp));          
        }
        dp[idx][buy][limit] = profit;
        return dp[idx][buy][limit];
    }
    int solveTab(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;
                if (buy){
                    profit =  -prices[idx] + dp[idx+1][0];
                    profit = max(profit, 0 + dp[idx+1][1]);
                }else{
                    profit =  prices[idx] + dp[idx+1][1];
                    profit = max(profit, 0 + dp[idx+1][0]);          
                }
                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2,vector<int>(4, -1)));
        return solve(0, 1, 2, prices, dp);
    }
};