#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void sumset(vector<int>&nums, int idx, int sum, bool & flag){
    if (idx < 0) return ;
    if (sum < 0) return ;
    if (sum == 0){
        flag = true;
        return ;
    }
    if (nums[idx] > sum){
        sumset(nums, idx-1, sum, flag);
        return ;
    }
    sumset(nums, idx-1, sum, flag);
    sumset(nums, idx-1, sum-nums[idx], flag);
}

bool isSubsetSum(vector<int>&set, int n, int sum)
{
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
 
    // If last element is greater than sum,
    // then ignore it
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);
 
    // Else, check if sum can be obtained by any
    // of the following:
    // (a) including the last element
    // (b) excluding the last element
    return isSubsetSum(set, n - 1, sum)
           || isSubsetSum(set, n - 1, sum - set[n - 1]);
}



int main() {
    int size, sum;
    cin >> size;
    vector<int>  nums(size);
    for(int i = 0; i < size; i++){
        cin >> nums[i];
    }
    cin >> sum;
    bool flag = false;
    flag = isSubsetSum(nums, size, sum);
    if (flag) cout << "True";
    else cout << "False";
    return 0;
}
