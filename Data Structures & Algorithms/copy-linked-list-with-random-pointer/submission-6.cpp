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

        unordered_map<Node*, Node*> mapa;

        if(!head) {
            return nullptr;
        }
        
        Node* curr = head;
        while(curr) {
            Node* novi = new Node(curr->val);
            mapa[curr] = novi;
            curr=curr->next;
        }

        curr = head;
        while(curr) {
            Node* novi = mapa[curr];
            novi->next = mapa[curr->next];
            novi->random = mapa[curr->random];
            curr = curr->next;
        }
        
        return mapa[head];
    }
};
