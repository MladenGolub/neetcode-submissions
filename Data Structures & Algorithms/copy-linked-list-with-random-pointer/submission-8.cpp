/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        map<Node*, Node*> mapaKopija;
        if(!head) return nullptr;
        Node* newHead = new Node(head->val);
        mapaKopija[head] = newHead;

        Node* curr = head->next;
        Node* newCurr = newHead;

        while(curr) {
            Node* novi = new Node(curr->val);
            mapaKopija[curr] = novi;
            newCurr->next = novi;
            newCurr = novi;
            curr = curr->next;
        }

        curr = head;

        while(curr) {
            if(curr->random) {
                mapaKopija[curr]->random = mapaKopija[curr->random];
            }
            curr = curr->next;
        }

        return newHead;

    }
};
