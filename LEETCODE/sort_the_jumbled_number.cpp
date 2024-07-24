#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int changeNum(int n, vector<int>& mapping){
        int result = 0;
        int ten = 1;
        if (n==0) return mapping[n];
        while(n>0){
            int ele = n % 10;
            result += ten * mapping(ele);
            n = n / 10;
            ten = ten * 10;
        }
        return result;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int, vector<int>>mp;
        for(auto n:nums){
            map[changeNum(n)].push_back(n);
        }
        vector<int> ans;
        for(auto ele:mp){
            for(auto item:ele.second){
                ans.push_back(item);
            }
        }
        return ans;
    }
};