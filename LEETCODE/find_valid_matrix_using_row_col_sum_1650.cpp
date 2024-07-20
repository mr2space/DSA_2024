#include<iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size(), 0));
        for(int j = 0; j < colSum.size(); j++){
            for(int i=0; i<rowSum.size(); i++){
                if (rowSum[i] < colSum[j]){
                    ans[i][j] = rowSum[i];
                    colSum[j] = (colSum[j]-rowSum[i]);
                    rowSum[i] = 0;
                }else{
                    ans[i][j] = colSum[j];
                    rowSum[i] = (rowSum[i]-colSum[j]);
                    colSum[j] = 0;
                }
            }
        }
        return ans;
    }
};