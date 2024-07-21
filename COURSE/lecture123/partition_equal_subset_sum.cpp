#include<iostream>
#include <vector>
using namespace std;



class Solution{
public:
    int solveTab(int N, int arr[], int total){
        vector<vector<int>> dp(N+1, vector<int>(total+1, 0));
        for(int i=0; i<=N; i++){
            dp[i][0] = 1;
        }
        
        for(int i=N-1; i>=0; i--){
            for(int j=0; j<=total/2; j++){
                int incl = 0;
                if (j-arr[i] >= 0)
                    incl = dp[i+1][j-arr[i]];
                int excl = dp[i+1][j];
                dp[i][j] = incl or excl;
            }
        }
        return dp[0][total/2];
        
    }
    int equalPartition(int N, int arr[])
    {
       int total = 0;
       for(int i=0; i<N; i++){
           total += arr[i];
       }
       if (total & 1){
           return 0;
       }
       return solveTab(N, arr, total);
       
    }
};

