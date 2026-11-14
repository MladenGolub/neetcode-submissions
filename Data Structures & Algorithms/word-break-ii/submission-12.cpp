class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        vector<bool> canSegment(n + 1, false);
        canSegment[n] = true;

        for(int i = n - 1; i >= 0; i--) {
            for(string word : wordDict) {
                int len = word.size();
                if(i + len <= n && s.compare(i, len, word) == 0 && canSegment[i + len]) {
                    canSegment[i] = true;
                    break;
                }
            }
        }

        if(!canSegment[0]) return {};

        vector<string> res;

        backtrack(0, s, wordDict, res);

        return res;

    }

    void backtrack(int indexSent, string sent, vector<string>& wordDict, vector<string>& res) {

        if(indexSent >= sent.size()) {
            sent.pop_back();
            res.push_back(sent);
            return;
        }

        for(int i = 0; i < wordDict.size(); i++) {
            if(isAtStart(sent, wordDict[i], indexSent)) {
                string novi = sent;
                novi.insert(indexSent + wordDict[i].size(), " ");
                backtrack(indexSent + 1 + wordDict[i].size(), novi, wordDict, res);
            }
        }

    }

    bool isAtStart(string s, string word, int indexSent) {
        if(indexSent + word.size() > s.size()) {
            return false;
        }

        for(int i = 0; i < word.size(); i++) {
            if(s[indexSent + i] != word[i]) return false;
        }

        return true;
    } 
};




