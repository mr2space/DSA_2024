#include<iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    long long solve(int M, int N, int X){
        vector<vector<long long>> dp(N+1, vector<long long>(X+1, 0));
        dp[0][0] = 1;
        for(int dice=1; dice<= N; dice++){
            for(int target = 1; target <= X; target++){
                long long int ans = 0;
                for(int face = 1; face <= M; face++){
                    if (target-face >= 0){
                        ans += dp[dice-1][target-face];
                    }
                }
                dp[dice][target] = ans;
            }
        }
        return dp[N][X];

    }

    long long noOfWays(int M , int N , int X) {
        return solve(M, N, X);
    }
};