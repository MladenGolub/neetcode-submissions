/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

    map<Node*, Node*> mapa;

public:
    Node* cloneGraph(Node* node) {
        
        if(node == nullptr) return nullptr;

        if(mapa.find(node) != mapa.end()) {
            return mapa[node]; 
        } 
        Node* curr = new Node(node->val);
        mapa.insert({node, curr});//cuvamo, da znamo da smo za stari node napravili novi, tj njegovu kopiju
        for(int i = 0; i < node->neighbors.size(); i++) {
            curr->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return curr;
    }
};




