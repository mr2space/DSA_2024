#include<iostream>
#include <vector>
#include <climits>
using namespace std;




class Solution {
public:
    int solve(vector<int>& obstacles, int currpos, int currlane, vector<vector<int>> &dp){
        int n = obstacles.size() - 1;
        if (currpos == n){
            return 0;
        }
        if (dp[currpos][currlane] != -1) return dp[currpos][currlane];
        int ans = INT_MAX;
        if (obstacles[currpos+1] != currlane){
            return solve(obstacles, currpos+1, currlane, dp);
        }else{
            for(int i=1; i<=3; i++){
                if ((i != currlane) && obstacles[currpos] != i)
                    ans = min(ans, 1+solve(obstacles, currpos, i, dp));
            }
        }
        dp[currpos][currlane] = ans;
        return dp[currpos][currlane];
    }
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(obstacles.size()+1, vector<int>(4, -1));
        return solve(obstacles, 0, 2, dp);
    }
};