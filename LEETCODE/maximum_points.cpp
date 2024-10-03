#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int ROWS = points.size();
        int COLS = points[0].size();
        int maxi = 0;
        vector<int> row(points[0].begin(), points[0].end());

        for(int r = 1; r < ROWS; r++){
            vector<int> next_row(points[r].begin(), points[r].end());
            vector<int> left(points[0].size(), 0);
            vector<int> right(points[0].size(), 0);

            left[0] = row[0];
            for(int c=1; c<COLS; c++){
                left[c] += max(row[c], left[c-1]-1);
            }
            right[COLS-1] = row[COLS-1];
            for(int c=COLS-2; c>=0; c--){
                right[c] += max(row[c], right[c+1]-1);
            }
            
            for(int c=0; c<COLS; c++){
                next_row[c] += max(left[c], right[c]);
                maxi = max(maxi, next_row[c]);
            }
            row = next_row;
        }
        return maxi;
    }
};