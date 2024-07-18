#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    bool isExist(vector<int> &to_delete, int value){
        for(auto ele:to_delete){
            if (ele == value) return true;
        }
        return false;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> mp;
        for(auto ele:nums){
            mp[ele] = 1;
        }
        ListNode *result = new ListNode(-1);
        ListNode * ans = result;
        ListNode * ptr = head;
        while(ptr != NULL){
            if (!mp[ptr->val]){
                ans->next = ptr;
                ans = ans->next;
                ptr = ptr->next;
            }else{
                ptr = ptr->next;
            }
            
        }
        return result->next;

    }
};