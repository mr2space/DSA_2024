#include<iostream>
#include <vector>
#include <climits>
using namespace std;


class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> a(s.length()-1, 0);
        vector<int> b(s.length()-1, 0);
        if (s.length() == 1){
            return 0;
        }
        if (s.length() == 2 && (s[0] == 'b' && s[1] == 'a')){
            return 1;
        }

        for(int i=1; i<s.length()-1; i++){
            int temp = b[i-1];
            if (s[i-1] == 'b'){
                temp += 1;
            }
            b[i] = temp;
        }

        for(int j=s.length()-3; j>=0; j--){
            int temp = a[j+1];
            if (s[j+1] == 'a'){
                temp += 1;
            }
            a[j] = temp;
        }

        int mini = INT_MAX;

        for(int k=0; k<a.size(); k++){
            mini = min(mini, a[k]+b[k]);
        }
        return mini;
    }
};