class TrieNode {
public:

    TrieNode* children[26] = {nullptr};
    bool isEnd;

    TrieNode(bool val=false) {isEnd = false;}

    void addWord(string word) {
        TrieNode* cur = this;

        for(char c : word) {
            if(!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new TrieNode();
            } 
            cur = cur->children[c - 'a'];
        }

        cur->isEnd = true;
    }
};


class Solution {
private:

    vector<vector<bool>> visited;
    vector<string> ret;

public:

    void dfs(int r, int c, TrieNode* root, vector<vector<char>>& board, string curWord) {

        int rows = board.size();
        int cols = board[0].size();

        if(r < 0 || c < 0 || r >= rows || c >= cols || visited[r][c] || !root || !root->children[board[r][c] - 'a']) {
            return;
        } 

        visited[r][c] = true;
        root = root->children[board[r][c] - 'a'];
        curWord += board[r][c];
        if(root && root->isEnd) {
            ret.push_back(curWord);
            root->isEnd = false;
        }

        dfs(r+1, c, root, board, curWord);
        dfs(r-1, c, root, board, curWord);
        dfs(r, c+1, root, board, curWord);
        dfs(r, c-1, root, board, curWord);

        visited[r][c] = false;

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(string word : words) {
            root->addWord(word);
        }

        int r = board.size();
        int c = board[0].size();

        visited.assign(r, vector<bool>(c, false));//za svako polje pamtimo da li smo ga obisli

        for(int i = 0; i < r; i ++) {
            for(int j = 0; j < c; j++) {
                dfs(i, j, root, board, "");
            }
        }

        return ret;
    }
};



