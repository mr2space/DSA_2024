#include<iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies+N);
        int mini = 0;
        int free = N-1;
        int buy = 0;
        while(buy <= free){
            mini = mini + candies[buy];
            buy++;
            free = free - K;
        }

        int maxi = 0;
        free = 0;
        buy = N-1;
        while(free <= buy){
            maxi = maxi + candies[buy];
            buy--;
            free = free + K;
        }
        return {mini, maxi};
    }
};