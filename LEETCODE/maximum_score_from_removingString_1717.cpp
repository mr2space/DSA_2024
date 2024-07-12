#include<iostream>
#include<unordered_map>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:// ab
    pair<string, int> counter(string &s, int val, string sub){
        string st;
        int score = 0;
        for(auto ele:s){
            if (st.empty()){
                st.push_back(ele);
                continue;
            }
            if (ele == sub[1] && st.back() == sub[0]){
                score += val;
                st.pop_back();
            }else{
                st.push_back(ele);
            }
        }
        return make_pair(st, score);
    }
    int solve(string s, int x, int y, unordered_map<string, int>& dp){
        int score = 0;
        if (x>y){
            pair<string, int> temp;
            temp = counter(s, x, "ab");
            score = temp.second + counter(temp.first, y, "ba").second;
        }else{
            pair<string, int> temp;
            temp = counter(s, x, "ba");
            score = temp.second + counter(temp.first, y, "ab").second;
        }
        return score;
    }

    int maximumGain(string s, int x, int y) {
        unordered_map<string, int> dp;
        return solve(s, x, y, dp);
    }
};