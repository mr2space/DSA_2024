#include<iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int, int>&a, pair<int, int>&b){
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> temp;
        for(int i=0; i<n; i++){
            temp.push_back({start[i], end[i]});
        }

        sort(temp.begin(), temp.end(), cmp);

        int count = 1;
        int prev_end = temp[0].second;
        for(int i=1; i<n; i++){
            if (prev_end < temp[i].first){
                prev_end = temp[i].second;
                count++;
            }
        }
        return count;
    }
};