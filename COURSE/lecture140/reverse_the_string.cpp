#include<iostream>
using namespace std;

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string ans = "";
        string temp = "";
        for(int i=S.length()-1; i>=0; i--){
            if (S[i] == '.'){
                reverse(temp.begin(), temp.end());
                temp.push_back('.');
                ans += temp;
                temp = "";
            }else{
                temp.push_back(S[i]);
            } 
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    } 
};
