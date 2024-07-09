#include<iostream>;
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode * curr = head->next;
        ListNode * prevMain = head->next;
        ListNode * q;
        while(curr != NULL){
            prevMain = curr;
            curr = curr->next;
            while(curr->val != 0){
                prevMain->val += curr->val;
                q = curr;
                curr = curr->next ;
                delete q;
            }
            q = curr;
            curr = curr->next;
            prevMain->next = curr;
            delete q;
        }

        return head->next;
    }
};