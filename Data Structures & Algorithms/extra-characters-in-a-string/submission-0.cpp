class Trie {
public:

    struct TrieNode {
        unordered_map<char, TrieNode*> childeren;
        bool isWord = false;
        TrieNode(bool word = false) : isWord(word) {}
    };

    Trie() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* cur = root;

        for(char c : word) {
            if(cur->childeren.find(c) == cur->childeren.end()) {
                cur->childeren[c] = new TrieNode();
            }
            cur = cur->childeren[c];
        }
        cur->isWord = true;
    }

    bool findWord(string word) {
        TrieNode* cur = root;

        for(char c : word) {
            if(cur->childeren.find(c) == cur->childeren.end()) {
                return false;
            }
            cur = cur->childeren[c];
        }

        return cur->isWord;

    }    

    Trie::TrieNode* getRoot() {
        return this->root;
    }

private:
    Trie::TrieNode* root;

};


class Solution {

    int backtrack(string& s, Trie* trie, int i, vector<int>& dp) {

        if(i == s.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int res = 1 + backtrack(s, trie, i+1, dp);
        Trie::TrieNode* cur = trie->getRoot();

        for(int j = i; j < s.size(); j++) {
            if(cur->childeren.find(s[j]) == cur->childeren.end()) break;
            cur = cur->childeren[s[j]];
            if(cur->isWord) {
                res = min(res, backtrack(s, trie, j + 1, dp));
            }
        }

        dp[i] = res;
        return res;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie* trie = new Trie();
        for(int i = 0; i < dictionary.size(); i++) {
            trie->addWord(dictionary[i]);
        }//dodali smo sve reci iz recnika u trie

        vector<int> dp(s.size() + 1, -1);

        return backtrack(s, trie, 0, dp);

    }
};