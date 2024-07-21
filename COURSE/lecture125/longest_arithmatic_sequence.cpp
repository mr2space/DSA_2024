#include<iostream>
using namespace std;

class Solution{   
public:
    int solve(int idx, int diff, int A[]){
        if (idx < 0) return 0;
        int ans = 0;
        for(int j=idx-1; j>=0; j--){
            if (A[idx]-A[j] == diff)
                ans = max(ans, 1 + solve(j, diff, A));
        }
        return ans;
    }

    int lengthOfLongestAP(int A[], int n) {
        if (n<=2) return n;
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans = max(ans, 2 + solve(i, A[j]-A[i], A));
            }
        }
        return ans;
    }
};