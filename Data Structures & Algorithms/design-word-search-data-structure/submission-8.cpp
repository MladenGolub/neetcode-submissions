class WordDictionary {
private:

    struct TrieNode {
        TrieNode* slova[26] = {};
        bool isEnd;

        TrieNode(bool val = false) : isEnd(val) {}
    };

    TrieNode* root;

    bool dfs(TrieNode* node, const string& word, int i) {
        if (i == word.size()) return node->isEnd;

        char c = word[i];
        if (c == '.') {
            for (TrieNode* s : node->slova) {
                if (s != nullptr && dfs(s, word, i + 1)) return true;
            }
            return false;
        }

        TrieNode* next = node->slova[c - 'a'];
        return next != nullptr && dfs(next, word, i + 1);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->slova[c - 'a'] == nullptr) {
                cur->slova[c - 'a'] = new TrieNode();
            }
            cur = cur->slova[c - 'a'];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};