#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(string &s, string &p, int i, int j, vector<vector<int>>& dp){
        if (i<0 && j<0) return 1;
        if (i>=0 && j<0) return 0;
        if (i<0 && j>=0){
            for(int k=0; k<=j; k++){
                if (p[k] != '*'){
                    return 0;
                }
            }
            return 1;
        }
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if (s[i] == p[j] || p[j] == '?'){
            ans =  solve(s, p, i-1, j-1, dp);
        }else if (p[j] == '*'){
            ans =  (solve(s, p, i, j-1, dp) || solve(s, p, i-1, j, dp));
        }else{
            ans =  false;
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
        return solve(s, p, s.length()-1, p.length()-1, dp);
    }
};