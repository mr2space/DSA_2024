#include<iostream>
#include <bits/stdc++.h> 
#include<string>

using namespace std;


class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        sort(arr+l,arr+r+1);
        return arr[k-1];
    }
};



int main(){
    int arr[] = { 7, 10, 4, 20, 15};
    int k = 4;
    int l = 0, r = 4;
    Solution a = Solution();
    cout << a.kthSmallest(arr, l, r, k) << endl;
}