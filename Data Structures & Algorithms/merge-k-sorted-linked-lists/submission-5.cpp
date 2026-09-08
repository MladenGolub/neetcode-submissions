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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if(l1 != nullptr) {
            curr->next = l1;
        } else {
            curr->next = l2;
        }

        return dummy->next;

    }

public:
//RADI ALI NIJE DOVOLJNO EFIKASNO   
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()) return nullptr;

        while(lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for(int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1) < lists.size() ? lists[i + 1] : nullptr;
                mergedLists.push_back(mergeTwoLists(l1, l2));
            }
            lists = mergedLists;
        }

        return lists[0];

    }
};
