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

    ListNode* reverseList(ListNode* head, int k) {
        //zelim da napravim fju koja ce da mi obrne listu koju posaljem, ali samo onoliko cvorova koliko joj dam
    
        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        while(k > 0) {
            ListNode* pom = curr->next;
            curr->next = prev;
            prev = curr;
            curr = pom;
            k--;
        }

        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
    //fju reverseList trebam da zovem samo ako sam siguran da u toj listi koju zelim da obrnem imam tacno k clanova, jer ako nemam nastace problem pristupa
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = head;
        ListNode* reverse = head;
        ListNode* prev = dummy;
        int cnt = 0;

        while(cur != nullptr) {
            cur = cur->next;
            cnt++;
            if(cnt == k) {
                ListNode* pom = reverseList(reverse, k);
                prev->next = pom;
                reverse->next = cur;
                prev = reverse;
                reverse = cur;
                cnt = 0;
            }
        }

        return dummy->next;

    }
};
