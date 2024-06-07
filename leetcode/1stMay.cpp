#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = 0;
        for(auto ele: word){
            if (ele == ch){
                break;
            }
            idx += 1;
        }
        if (idx == word.length()) return word;
        int j = 0;
        int temp = idx /2;
        char ele ;
        while (j <= temp){
            ele = word[idx];
            word[idx] = word[j];
            word[j] = ele;
            idx--;
            j++;
        }       
        return word;
    }
};



int main(){
    Solution a = Solution();
    cout << a.reversePrefix("xyxzxe",'z') << endl;
    return 0;
}