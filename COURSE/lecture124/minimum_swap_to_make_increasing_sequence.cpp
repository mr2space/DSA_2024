#include<iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int idx, int swapped, vector<vector<int>>& dp){
        if (idx == nums1.size()) return 0;
        if (dp[idx][swapped] != -1) return dp[idx][swapped];
        int prev1 = nums1[idx-1];
        int prev2 = nums2[idx-1];
        int ans = INT_MAX;
        if (swapped){
            swap(prev1, prev2);
        }

        if (nums1[idx]>prev1 && nums2[idx]>prev2){
            ans = solve(nums1, nums2, idx+1, 0, dp);
        }
        if (nums1[idx] > prev2 && nums2[idx] > prev1){
            ans = min(ans,1+solve(nums1, nums2, idx+1, 1, dp));
        }
        dp[idx][swapped] = ans;
        return dp[idx][swapped];

    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int swapped = 0;
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
        return solve(nums1, nums2, 1, swapped, dp);
    }
};