#include<iostream>
#include <vector>
using namespace std;

class Solution_DP {
public:
    bool solve(vector<int>& nums, int idx, vector<int>& dp){
        if (idx >= nums.size()-1) return true;
        if (nums[idx] == 0) return false;
        if (dp[idx] != -1) return dp[idx];
        int n = nums[idx];
        bool result = 0;
        for(int i=1; i<=n; i++){
            result = result || solve(nums, idx+i, dp);
        }
        dp[idx] = result;
        return dp[idx];
    }
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};


class Solution_Greedy {
public:
    bool canJump(vector<int>& nums) {
        int target = nums.size()-1;
        for(int idx=nums.size()-2; idx>=0; idx--){
            if (target <= idx + nums[idx]){
                target = idx;
            }
        }
        return target == 0;
    }
};