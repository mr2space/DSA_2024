#include<iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;



class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_map<int, int> row_mp; // { row_no : min_in_row };
        unordered_map<int, int> col_mp; // { col_no : max_in_row };

        for(int i=0; i<matrix.size(); i++){
            int mini = INT_MAX;
            for(int j=0; j<matrix[0].size(); j++){
                if (matrix[i][j] < mini){
                    mini = matrix[i][j];
                }
            }
            row_mp[i] = mini;
        }


        for(int i=0; i<matrix.size(); i++){
            int maxi = INT_MIN;
            for(int j=0; j<matrix[0].size(); j++){
                if (matrix[j][i] > maxi){
                    maxi = matrix[j][i];
                }
            }
            col_mp[i] = maxi;
        }
        vector<int> ans;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if (matrix[i][j] == row_mp[i] && matrix[i][j] == col_mp[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;

    }
};