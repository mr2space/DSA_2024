#include<iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int capacity, int weight[], int price[], int n, int idx, vector<vector<int>>& dp){
        if (idx < 0){
            return 0;
        }
        if (dp[idx][capacity] != -1) return dp[idx][capacity];
        int notTake = 0 + solve(capacity, weight, price, n, idx-1, dp);
        int take = 0;
        if (capacity - weight[idx] >= 0){
            take = price[idx] + solve(capacity-weight[idx], weight, price, n, idx-1, dp);
        }
        return dp[idx][capacity] = max(notTake, take);
    }

    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n, vector<int>(W+1, -1));
       return solve(W, wt, val, n, n-1, dp);
    }
};




class Solution2
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int capacity, int weight[], int price[], int n){
        vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

        for(int j=weight[0]; j <= capacity; j++){
            if (weight[0] <= capacity)
                dp[0][j] = price[0];
        }


        for(int c=1; c<=capacity; c++){
            for(int idx=1; idx<n; idx++){
                int notTake = dp[idx-1][c];
                int take = 0;
                if (c - weight[idx] >= 0){
                    take = price[idx] + dp[idx-1][c-weight[idx]];
                }
                dp[idx][c] = max(notTake, take);
            }
        }
        return dp[n-1][capacity];

    }

    int knapSack(int W, int wt[], int val[], int n) 
    {
        return solve(W, wt, val, n);
    }
};