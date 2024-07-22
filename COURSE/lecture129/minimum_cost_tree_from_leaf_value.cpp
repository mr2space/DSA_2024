#include<iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;


// incomplete
class Solution {
public:
    int solve(vector<int>& arr, map<pair<int, int>, int> maxi, int left, int right, vector<vector<int>> &dp){
        if (left == right) return 0;
        int ans = INT_MAX;
        if (dp[left][right] != -1) return dp[left][right];
        for(int i=left; i<right; i++){
            ans = min(ans, maxi[{left, i}]*maxi[{i+1, right}]+solve(arr, maxi, left, i, dp) + solve(arr, maxi, i+1, right, dp));
        }
        dp[left][right] = ans;
        return dp[left][right];
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;
        vector<vector<int>> dp(arr.size()+1, vector<int>(arr.size()+1, -1));
        for(int i=0; i<arr.size(); i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1; j<arr.size(); j++){
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }
        return solve(arr, maxi, 0, arr.size()-1, dp);
    }
};