#include<iostream>
#include <vector>
using namespace std;




class Solution {
public:
    bool check(vector<int> base, vector<int> nextBase){
        if (base[0] <= nextBase[0] && base[1] <= nextBase[1] && base[2] <= nextBase[2]){
            return true;
        }
        return false;
    }
    int solveTab(int n, vector<vector<int>>& a){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
                int take = 0;
                if (prev == -1 || check(a[prev], a[curr])){
                    take = a[curr][2] + dp[curr+1][curr+1];
                }
                int nottake = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(take, nottake);
            }
        }
        return dp[0][0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a: cuboids){
            sort(a.begin(), a.end());
        }
        sort(cuboids.begin(), cuboids.end());
        return solveTab(cuboids.size(), cuboids);
    }
};