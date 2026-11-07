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
        
        ListNode* last = head->next;
        ListNode* prev = new ListNode(head->val);
        int cnt = 0;
        while(last) {
            ListNode* node = new ListNode(last->val);
            node->next = prev;
            prev = node;
            last = last->next;
            cnt++;
        }

        ListNode* ret = head;
        ListNode* tail = nullptr;
        int i = 0;
        while(cnt > 0) {
            if(i % 2 != 1) {
                ListNode* pom = head->next;
                head->next = prev;
                tail = prev;
                head = pom;
            } else {
                ListNode* pom = prev->next;
                prev->next = head;
                tail = head;
                prev = pom;
            }
            cnt--;
            i++;
        }

        head = ret;

        if(tail) tail->next = nullptr;

    }
};
