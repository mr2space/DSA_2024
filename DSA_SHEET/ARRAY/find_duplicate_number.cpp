#include<iostream>
#include <vector>
using namespace std;



// floyd warshall algo
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        while (1){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast){
                break;
            }
        }
        int ptr1 = nums[0];
        int ptr2 = slow;

        while (1){
            if (ptr1 == ptr2) return ptr1;
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return 1;
    }
};