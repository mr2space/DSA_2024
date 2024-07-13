#include<iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <stack>
#include<queue>
using namespace std;

class compare{
    public:
    bool operator()(pair<int,int>a, pair<int,int>b){
        return a.second > b.second;
    };
};


class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq; // (idx, pos)
        int n = positions.size();
        for(int i=0; i<n; i++){
            pq.push({i, positions[i]});
        }
        stack<pair<int,int>> st; // (idx , direction)
        while (!pq.empty()){
            pair<int, int> ele = pq.top(); // (idx, pos)
            int ele_dir = (directions[ele.first] == 'R')?-1:1;
            if (st.empty()){
                st.push({ele.first, ele_dir});
                pq.pop();
                continue;
            }

            if (ele_dir > st.top().second){
                pair<int, int> temp = st.top(); // (idx , direction)
                st.pop();
                if (healths[temp.first] > healths[ele.first]){
                    healths[temp.first]--;
                    pq.pop();
                    pq.push({temp.first, positions[temp.first]});
                }else if (healths[temp.first] < healths[ele.first]){
                    healths[ele.first]--;
                }else{
                    pq.pop();
                }
            }else{
                st.push({ele.first, ele_dir});
                pq.pop();
            }
        }


        vector<int> ans(n,0);
        vector<int> result;
        while(!st.empty()){
            ans[st.top().first] = healths[st.top().first];
            st.pop();
        }
        for(int i=0; i<n; i++){
            if (ans[i] <= 0) continue;
            result.push_back(ans[i]);
        }
        return result;
    }
};

