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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head) return head;

        ListNode* prevLeftNode = nullptr;
        ListNode* leftNode = head;

        int cnt = 1;

        while(leftNode != nullptr && cnt != left) {
            prevLeftNode = leftNode;
            leftNode = leftNode->next;
            cnt++;
        }
        if(!leftNode) return head;
        //sada stojimo na cvoru koji ima val left

        ListNode* rightNode = leftNode;
        ListNode* pom;
        ListNode* sl = rightNode->next;
        while(cnt != right && rightNode && rightNode->next) {
            pom = rightNode;
            rightNode = sl;
            sl = rightNode->next;
            rightNode->next = pom;
            cnt++;
        }

        if(!prevLeftNode) {
            head = rightNode;
            leftNode->next = sl;
        } else {
            prevLeftNode->next = rightNode;
            leftNode->next = sl;
        }  

        return head;

    }
};