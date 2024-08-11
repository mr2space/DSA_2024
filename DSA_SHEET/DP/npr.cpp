#include<iostream>
using namespace std;



class Solution{
    public:
    int MOD = 1000000007;
    int permutationCoeff(int n, int k){
        long int p = 1;
        for(int i=0; i<k; i++){
            p = (p * (n-i)) % MOD;
        }
        return p % MOD;
    }
};

