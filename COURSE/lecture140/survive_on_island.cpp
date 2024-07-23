#include<iostream>
using namespace std;


// todo not complete
class Solution{
public:
    int minimumDays(int S, int N, int M){
        int sunday = S/7;
        int buy_day = S - sunday;
        int total_food = S * M;
        int ans = 0;
        if (total_food % N == 0) ans = total_food/N;
        else ans = total_food/N + 1;

        if (buy_day <= ans){
            return -1;
        }
        return ans;

    }
};