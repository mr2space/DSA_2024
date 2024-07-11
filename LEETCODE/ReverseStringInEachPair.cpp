#include<iostream>
#include<stack>
#include <queue>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string ans = "";
        stack<int> st;
        for(int i=0; i<n; i++){
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')' ){
                int startIdx = st.top()+1;
                int endIdx = i;
                reverse(s.begin()+startIdx, s.begin()+endIdx);
                st.pop();
            }
        }

        for(int i=0; i<n; i++){
            if (s[i] == '(' || s[i] == ')') continue;
            ans.push_back(s[i]);
        }
        return ans;

    }
};