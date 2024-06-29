#include<iostream>
#include <vector>
using namespace std;


string longestCommonPrefix(vector<string> &arr, int n)
{
   string ans = "";
   for(int i=0; i < arr[0].size(); i++){
        char ch = arr[0][i];
        bool flag = true;

        for(int j=1; j < arr.size(); j++){
            if(ch != arr[j][i]){
                flag = false;
                break;
            }
        }

        if (flag){
            ans.push_back(ch);
        }else{
            break;
        }
   }
   return ans;
   
}


