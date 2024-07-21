#include<iostream>
#include <vector>
using namespace std;




class Solution {
public:
    int solve(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if (idx == prices.size()) return 0;
        int profit = 0;
        if (dp[idx][buy] != -1) return dp[idx][buy];
        if (buy){
            profit =  -prices[idx] + solve(idx+1, 0, prices, dp);
            profit = max(profit, 0 + solve(idx+1, 1, prices, dp));
        }else{
            profit =  prices[idx] + solve(idx+1, 1, prices, dp);
            profit = max(profit, 0 + solve(idx+1, 0, prices, dp));          
        }
        dp[idx][buy] = profit;
        return dp[idx][buy];
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
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solveTab(prices);
    }
};