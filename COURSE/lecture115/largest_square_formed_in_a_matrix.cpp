#include<iostream>
#include <vector>
#include <climits>
using namespace std;



class Solution {
  public:
    int solve(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp){
        // base case
        if (i>=mat.size() || j>=mat[0].size() ){
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        int right = solve(mat, i, j+1, maxi, dp);
        int diag = solve(mat, i+1, j+1, maxi, dp);
        int down = solve(mat, i+1, j, maxi, dp);

        if (mat[i][j] == 1){
            int ans = 1 + min(right, min(diag, down));
            dp[i][j] = ans;
            maxi = max(maxi, ans); 
        }else{
            dp[i][j] = 0;
        }
        return dp[i][j];
    }

    int solveTab(vector<vector<int>> &mat, int n, int m){
        int maxi = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=n-1; i>= 0; i--){
            for(int j=m-1; j>=0; j--){
                int right = dp[i][j+1];
                int diag = dp[i+1][j+1];
                int down = dp[i+1][j];
                if (mat[i][j] == 1){
                    dp[i][j] = 1 + min(right, min(diag, down));
                    maxi = max(maxi, dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return maxi;

    }


    int maxSquare(int n, int m, vector<vector<int>> mat) {
        return solveTab(mat, n, m);
    }
};
