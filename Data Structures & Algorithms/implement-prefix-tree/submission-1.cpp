class PrefixTree {
private:

    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEnd;

        TrieNode(bool val=false): isEnd(val) {}
    };

    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode* curr = root;

        for(int i = 0; i < word.size(); i++) {

            if(curr->children.find(word[i]) == curr->children.end()) {
                curr->children[word[i]] = new TrieNode();
            }

            curr = curr->children[word[i]];

        }

        curr->isEnd = true;

    }
    
    bool search(string word) {
        
        TrieNode* curr = root;

        for(int i = 0; i < word.size(); i++) {
            
            if(curr->children.find(word[i]) == curr->children.end()) {
                return false;
            }

            curr = curr->children[word[i]];

        }

        return curr->isEnd;

    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for(int i = 0; i < prefix.size(); i++) {
            
            if(curr->children.find(prefix[i]) == curr->children.end()) {
                return false;
            }

            curr = curr->children[prefix[i]];

        }

        return true;
    }
};
