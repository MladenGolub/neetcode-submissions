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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        //pravimo prioritetni red, ali mu dajemo nasu fju da bude minHeap

        for(ListNode* l : lists) {
            if(l != nullptr) {
                minHeap.push(l);
            }
        }

        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        while(!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();
            curr->next = node;
            curr = curr->next;

            node = node->next;
            if(node != nullptr) {
                minHeap.push(node);
            } 
        }

        return res->next;
    }
};
