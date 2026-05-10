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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr) {
            return nullptr;
        } else if(l1 == nullptr) {
            return l2;
        } else if(l2 == nullptr) {
            return l1;
        }

        ListNode* result = nullptr;
        int carry = (l1->val + l2->val) / 10;
        result = new ListNode((l1->val + l2->val) % 10);
        ListNode* curr = result;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 != nullptr || l2 != nullptr) {
            if(l1 && l2) {
                ListNode* novi = new ListNode((l1->val + l2->val + carry) % 10);
                carry = (l1->val + l2->val + carry) >= 10 ? 1 : 0;
                curr->next = novi;
                curr = novi;
                l1 = l1->next;
                l2 = l2->next;
            } else if(l1 != nullptr) {
                ListNode* novi = new ListNode((l1->val + carry) % 10);
                carry = (l1->val + carry) >= 10 ? 1 : 0;
                curr->next = novi;
                curr = novi;
                l1 = l1->next;
            } else {
                ListNode* novi = new ListNode((l2->val + carry) % 10);
                carry = (l2->val + carry) >= 10 ? 1 : 0;
                curr->next = novi;
                curr = novi;
                l2 = l2->next;
            }
        }
        if(carry != 0) {
            ListNode* novi = new ListNode(carry);
            curr->next = novi;
        }
        return result;
    }
};
