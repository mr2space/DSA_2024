#include<iostream>
#include <vector>
using namespace std;


class Solution {
public:
    long long int  minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        long long int noOfHorizontalSection = 1;
        long long int noOfVerticalSection = 1;
        n = horizontalCut.size();
        m = verticalCut.size();
        long long int ans = 0;
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());
        long long int i=0, j=0;

        while(i<n && j<m){
            if (horizontalCut[i] >= verticalCut[j]){
                ans += noOfVerticalSection*horizontalCut[i];
                noOfHorizontalSection++;
                i++;
            }else{
                ans += noOfHorizontalSection*verticalCut[j];
                noOfVerticalSection++;
                j++;
            }
        }

        while(i<n){
            ans += noOfVerticalSection*horizontalCut[i];
            noOfHorizontalSection++;
            i++;
        }
        while(j<m){
            ans += noOfHorizontalSection*verticalCut[j];
            noOfVerticalSection++;
            j++;
        }
        return ans;
    }
};
