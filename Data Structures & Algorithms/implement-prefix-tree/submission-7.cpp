class PrefixTree {
private:

    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEnd;

        TrieNode(bool val = false) : isEnd(val) {}
    };

    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(char c : word) {
            if(cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isEnd = true;

    }
    
    bool search(string word) {
        
        TrieNode* cur = root;

        for(char c : word) {
            if(cur->children.find(c) == cur->children.end()) {
                return false;
            } else {
                cur = cur->children[c];
            }
        }

        return cur->isEnd;

    }
    
    bool startsWith(string prefix) {
        
        TrieNode* cur = root;

        for(char c : prefix) {
            if(cur->children.find(c) == cur->children.end()) {
                return false;
            } else {
                cur = cur->children[c];
            }
        }

        return true;

    }
};
