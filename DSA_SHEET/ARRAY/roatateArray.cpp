#include<iostream>
#include <vector>
using namespace std;


class Solution {
  public:
    void rotate(vector<int> &arr) {
        int n = arr.size();
        int last = arr[n-1];
        for(int i=n-1; i>=0; i--){
            arr[i+1] = arr[i];
        }
        arr[0] = last;
    }
};