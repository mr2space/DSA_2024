#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <climits>
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


int sumQ(queue<int>q){
    int total = 0;
    int temp;
    q.push(-1000000);
    while(q.front() != -100000){
        total += q.front();
        q.push(q.front());
        q.pop();
    }
    q.pop();
    return total;
}


// bool isSubsetSum2(queue<int> q, int sum)
// {
//     if (sum == sumQ(q))
//         return true;
//     if (q.empty())
//         return false;
//     int f = q.front();
//     q.pop();
//     if (f > sum)
//         return isSubsetSum(q, sum);
//     isSubsetSum(q, sum);
//     isSubsetSum(q, sum + f);
//     return true;
// }


bool isSubsetSum(vector<int>& arr,int idx, int total, int current_sum){
    if (total == current_sum) return true;
    if (idx < 0) return false;
    return isSubsetSum(arr, idx-1, total, current_sum) || isSubsetSum(arr, idx-1, total-arr[idx], current_sum+arr[idx]);
}   



int main() {
    int size, sum = 0;
    cin >> size;
    vector<int>  nums(size);
    for(int i = 0; i < size; i++){
        cin >> nums[i];
        sum += nums[i];
    }
    // cin >> sum;
    bool flag = false;
    flag = isSubsetSum(nums, size, sum, 0);
    if (flag) cout << "Yes ! we cab Divied the Array.";
    else cout << "Sorry ! we cannot divied the array.";
    return 0;
}









int frogenergy(int ind, vector<int>& a)
{
    if (ind == 0)
        return 0;
    int left
        = frogenergy(ind - 1, a) + abs(a[ind] - a[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        right = frogenergy(ind - 2, a)
                + abs(a[ind] - a[ind - 2]);
    return min(left, right);
}

int minBounceEnergy(int n, vector<int>& heights)
{
    return frogenergy(n - 1, heights);
}

int main()
{
    int n = 4;
    vector<int> heights = { 20, 30, 40, 20 };
    int result = minBounceEnergy(n, heights);
    cout << "Minimum energy exhausted: " << result << endl;
    return 0;
}