#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solveTab(vector<int>& prices, int fee){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;
                if (buy){
                    profit =  -prices[idx] + dp[idx+1][0];
                    profit = max(profit, 0 + dp[idx+1][1]);
                }else{
                    profit =  prices[idx] - fee + dp[idx+1][1];
                    profit = max(profit, 0 + dp[idx+1][0]);          
                }
                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        return solveTab(prices, fee);
    }
};