#include<iostream>
#include <vector>
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        vector<int> idx;
        ListNode* prev, *curr, *next;
        if (head->next == NULL || head->next->next == NULL) return {-1, -1};
        prev = head;
        curr = head->next;
        next = head->next->next;
        int i = 1;
        while(curr->next != NULL){
            if (curr->val > prev->val && curr->val > next->val){
                idx.push_back(i);
            }else if(curr->val < prev->val && curr->val < next->val){
                idx.push_back(i);
            }
            prev = curr;
            curr = next;
            if (next != NULL)
                next = next->next;
            i++;
        }
        if (idx.size() < 2){
            return {-1, -1};
        }
        sort(idx.begin(), idx.end());

        int maxi = (idx[idx.size()-1]-idx[0]);
        int mini = INT_MAX;

        for(int i=0; i<idx.size()-1; i++){
            mini = min(mini, idx[i+1]-idx[i]);
        }

        return {mini, maxi};


    }
};