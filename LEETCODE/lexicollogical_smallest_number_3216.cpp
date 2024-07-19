#include<iostream>
using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        for(int i=0; i<s.length()-1; i++){
            int num1 = atoi(&(s.substr(i,1)[0]));
            int num2 = atoi(&(s.substr(i+1,1)[0]));
            if ((num1 & 1 ) && (num2 & 1) && (num1 > num2)){
                swap(s[i], s[i+1]);
                break;
            }
            if (!(num1 & 1 ) && !(num2 & 1) && (num1 > num2)){
                swap(s[i], s[i+1]);
                break;
            }
        }
        return s;
    }
};