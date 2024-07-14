#include<iostream>
#include <vector>
#define MOD 1000000007
using namespace std;


long long int solve(int n){
    vector<long long int> dp(n+1, -1);
    dp[1] = 0;
    dp[2] = 1;
    for(int i=3; i<=n; i++){
        dp[i] = ((i-1)*((((dp[i-1])%MOD)+(dp[i-2]%MOD))%MOD))%MOD;
    }
    return dp[n];
}



long long int countDerangements(int n) {
    return solve(n);
}

