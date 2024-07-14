#include<iostream>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> mp;
        stack<pair<string, int>> st;
        int i = 0;
        while(i<formula.size()){
            if (formula[i] >= 'A' && formula[i] <= 'Z'){
                int len = 1;
                int num = 1;
                while((i+len < formula.size()) && formula[i+len] > 'Z'){
                    len++;
                }
                if ((i+len < formula.size()) && formula[i+len] <= '9' && formula[i+len] >= '1'){
                    num = atoi(&formula[i+len]);
                }
                string sub = formula.substr(i, len); // i+len-1
                mp[sub] = 0;
                st.push({sub, num});
                i = i+len;
            }else if (formula[i] == '('){
                st.push({"\0", -1});
                i++;
            }else if (formula[i] == ')'){
                int num = 1;
                if (i+1 < formula.size() && formula[i+1] <= '9' && formula[i+1] >= '1'){
                    num = atoi(&formula[i+1]);
                }
                stack<pair<string, int>> temp;
                
                while (!st.empty() && st.top().first != "\0"){
                    pair<string, int> ele = st.top();
                    temp.push({ele.first, ele.second*num});
                    st.pop();
                }
                st.pop();
                while (!temp.empty()){
                    st.push(temp.top());
                    temp.pop();
                }
                i++;
            }else{
                i++;
            }
        }


        while(!st.empty()){
            mp[st.top().first] += st.top().second;
            st.pop();
        }
        string ans = "";
        for(auto ele:mp){
            if (ele.second == 1){
                ans += ele.first;
            }else{
                ans = ans + ele.first + to_string(ele.second);
            }
        }

        return ans;
    }
};