#include<iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int solve(string text1, string text2, int i, int j, vector<vector<int>>& dp){
        if (i>=text1.length() || j>=text2.length()) return 0;
        int ans = 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (text1[i] == text2[j]){
            ans =  1 + solve(text1, text2, i+1, j+1, dp);
        }else{
            ans = max(solve(text1, text2, i+1, j, dp), solve(text1, text2, i, j+1, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveTab(string a, string b){
        vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));
        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);
        for(int i=a.length()-1; i>=0; i--){
            for(int j=b.length()-1; j>=0; j--){
                int ans = 0;
                if (a[i] == b[j]){
                    ans =  1 + next[j+1];
                }else{
                    ans = max(next[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];

    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        // return solve(text1, text2, 0, 0, dp);
        return solveTab(text1, text2);
    }
};