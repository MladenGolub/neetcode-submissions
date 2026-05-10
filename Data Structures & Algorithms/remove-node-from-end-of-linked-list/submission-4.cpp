/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* curr = head;
        while(curr != nullptr) {
            curr = curr->next;
            sz++;
        }
        if(sz == 1) {
            delete head;
            return nullptr;
        }
        int m = sz - n;
        curr = head;
        ListNode* prev = nullptr;
        while(m != 0) {
            prev = curr;
            curr = curr->next;
            m--;
        }
        if(curr) {
            if(prev) {
                prev->next = curr->next;
                curr->next = nullptr;
                delete curr;
            } else {
                head = head->next;
                delete curr;
            }
        }
        return head;
    }
};
