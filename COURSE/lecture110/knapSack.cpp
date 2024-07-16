#include <bits/stdc++.h>  
#include<iostream>
using namespace std;


int solve(vector<int> &weight, vector<int> &value, int n, int capacity){
    vector<vector<int>> dp(n, vector<int>(capacity+1, 0));
    
    for(int w=weight[0]; w<=capacity; w++){
        if (weight[0] <= capacity){
            dp[0][w] = value[0];
        }else{
            dp[0][w] = 0;
        }
    }

    for(int idx=1; idx < n; idx++){
        for(int w=0; w<=capacity; w++){
            int include = 0;
            if (weight[idx] <= w){
                include = value[idx] + dp[idx-1][w-weight[idx]];
            }
            int exclude = dp[idx-1][w];
            dp[idx][w] = max(include, exclude);
        }
    }

    return dp[n-1][capacity];

}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(weight, value, n, maxWeight);
}