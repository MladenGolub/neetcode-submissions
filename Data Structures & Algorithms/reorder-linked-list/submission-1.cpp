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

    void reorderList(ListNode* head) {
        ListNode* last = head;
        ListNode* secondLast = nullptr;
        while(last->next != nullptr) {
            secondLast = last;
            last = last->next;
        }
        
        ListNode* curr = head->next;
        ListNode* prev = head;
        
        while((curr != nullptr && curr->next != nullptr)) {
            if(last) {
                prev->next = last;
                last->next = curr;
                secondLast->next = nullptr;
            }
            prev = curr;
            curr = curr->next;
            last = head;
            while(last->next != nullptr) {
                secondLast = last;
                last = last->next;
            }   
        }
    }

};
