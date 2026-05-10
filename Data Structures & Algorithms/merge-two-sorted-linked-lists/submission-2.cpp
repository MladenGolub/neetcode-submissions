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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(!list1) {
            return list2;
        } else if(!list2) {
            return list1;
        } else if(list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }

        ListNode* curr = nullptr;
        ListNode* head = nullptr;

        if(list1->val <= list2->val) {
            curr = list1; 
            head = list1; 
            list1 = list1->next;
        } else {
            curr = list2; 
            head = list2; 
            list2 = list2->next;
        }
        while(list1 != nullptr && list2 != nullptr) {
            
            if(list1->val <= list2->val) {
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            } else {
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }
        
        }
        if(list1 == nullptr) {
            curr->next = list2;
            return head;
        } else {
            curr->next = list1;
            return head;
        }
    }
};
