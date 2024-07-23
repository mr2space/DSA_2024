#include<iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:

    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        for(auto ele:nums){
            mp[ele]++;
        }
        map<int, vector<int>>freq;
        for(auto ele:mp){
            freq[ele.second].push_back(ele.first);
        }
        vector<int> ans;
        for(auto ele:freq){
            sort(ele.second.begin(), ele.second.end(), greater<int>());
            for(auto item:ele.second){
                for(int i=1; i<=ele.first; i++)
                    ans.push_back(item);
            }
        }
        return ans;
    }
};



class Solution2 {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;
        for (int n : nums) {
            frequencyMap[n]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (frequencyMap[a] != frequencyMap[b]) {
                return frequencyMap[a] < frequencyMap[b];
            }
            return a > b;
        });
        return nums;
    }
};