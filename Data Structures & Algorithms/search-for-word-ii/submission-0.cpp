class TrieNode{
public:
    unordered_map<char, TrieNode*> childeren;
    bool isWord;
    TrieNode(bool isWord = false) : isWord(isWord) {} 

    void addWord(string word) {
        TrieNode* cur = this;

        for(char c : word) {
            if(cur->childeren.find(c) == cur->childeren.end()) {
                cur->childeren[c] = new TrieNode();
            }
            cur = cur->childeren[c];
        }

        cur->isWord = true;
    }
};

class Solution {
    unordered_set<string> res;
    vector<vector<bool>> visit;

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, string word) {
        int r = board.size();
        int c = board[0].size(); 
        if(i < 0 || j < 0 || i >= r || j >= c || !root->childeren[board[i][j]] || visit[i][j]) {
            return;
        }

        visit[i][j] = true;
        root = root->childeren[board[i][j]];
        word += board[i][j];
        if(root->isWord) {
            res.insert(word);
        }

        dfs(board, i-1, j, root, word);
        dfs(board, i+1, j, root, word);
        dfs(board, i, j-1, root, word);
        dfs(board, i, j+1, root, word);

        visit[i][j] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        TrieNode* root = new TrieNode();
        for(string& s : words) {
            root->addWord(s);
        }

        int r = board.size();
        int c = board[0].size();
        
        visit.assign(r, vector<bool>(c, false));

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, "");
            }
        }

        return vector<string>(res.begin(), res.end());

    }
};
