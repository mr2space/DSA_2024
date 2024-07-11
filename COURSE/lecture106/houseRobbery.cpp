#include <bits/stdc++.h> 

using namespace std;


long long int solve(vector<int>&nums){
    int n = nums.size();
    long long int prev1 = 0;
    long long int prev2 = nums[0];
    long long int ans = 0;
    for(int i=1; i<n; i++){
        long long int incl = prev1 + nums[i];
        long long int excl = prev2 + 0;
        ans = max(incl, excl);
        prev1 = prev2;
        prev2 = ans;
    }
    return prev2;
}
long long int houseRobber(vector<int>& valueInHouse)
{
   vector<int> first, second;
   int n = valueInHouse.size();
   if (n==1) return valueInHouse[0];
   for(int i=0; i<n; i++){
        if ( i != n-1){
            first.push_back(valueInHouse[i]);
        }
        if ( i!=0 ){
            second.push_back(valueInHouse[i]);
        }
   }
   return max(solve(first), solve(second));
}