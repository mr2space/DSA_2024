#include<iostream>
#include <vector>
using namespace std;


class Solution{
public:
    int MOD = 1000000007;
    int solve(int n, int r, vector<vector<int>> &dp){
        if (r==0 || n==r){
            return 1;
        }
        if (dp[n][r] != -1) return dp[n][r];
        return dp[n][r] = ((solve(n-1, r-1, dp)%MOD) + (solve(n-1, r, dp)%MOD))%MOD;
    }
    int nCr(int n, int r){
        vector<vector<int>>dp(n+1, vector<int>(r+1));
        return solve(n,r,dp);
    }
};


class Solution2{
public:
    int MOD = 1000000007;
    int solve(int n, int r){
        vector<vector<int>>dp(n+1, vector<int>(r+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
        for(int i=0; i<=n && i<=r; i++){
            dp[i][i] = 1;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=r; j++){
                dp[i][j] = (dp[i-1][j-1]%MOD + (dp[i-1][j])%MOD)%MOD;
            }
        }
        return dp[n][r];
    }
    int nCr(int n, int r){
        
        return solve(n,r);
    }
};