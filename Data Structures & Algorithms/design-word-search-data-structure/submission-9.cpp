class WordDictionary {
private:

    struct TrieNode {
        TrieNode* slova[26] = {nullptr};
        bool isEnd;

        TrieNode(bool val = false) : isEnd(val) {}
    };

    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        
        TrieNode* cur = root;
        for(char c : word) {
            if(cur->slova[c - 'a'] == nullptr) {
                cur->slova[c - 'a'] = new TrieNode();
            }
            cur = cur->slova[c - 'a'];
        }
        cur->isEnd = true;

    }
    
    bool search(string word) {
        // 3. bez tačaka: običan prolaz
        if (word.find('.') == string::npos) {
            TrieNode* cur = root;
            for (char c : word) {
                cur = cur->slova[c - 'a'];
                if (!cur) return false;
            }
            return cur->isEnd;
        }

        // 1. dva vektora koja se ponovo koriste
        vector<TrieNode*> cur = {root}, next;
        int n = word.size();

        for (int i = 0; i < n; i++) {
            char c = word[i];
            bool last = (i == n - 1);
            next.clear();

            for (TrieNode* node : cur) {
                if (c == '.') {
                    for (TrieNode* s : node->slova) {
                        if (!s) continue;
                        if (last && s->isEnd) return true;   // 2. rani izlaz
                        next.push_back(s);
                    }
                } else {
                    TrieNode* s = node->slova[c - 'a'];
                    if (!s) continue;
                    if (last && s->isEnd) return true;       // 2. rani izlaz
                    next.push_back(s);
                }
            }

            if (next.empty()) return false;
            swap(cur, next);
        }

        return n == 0 && root->isEnd;   // prazna reč; inače bismo već vratili true
    }
};
