class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<bool> dp(s.size()+1, false);

        dp[s.size()] = true;

        for(int i = s.size()-1; i>= 0; i--) {
            for(int j = 0; j < wordDict.size(); j++) {
                if(wordDict[j].size() <= s.size() - i) {
                    string pom = s.substr(i, wordDict[j].size());
                    if(pom == wordDict[j]) {
                        dp[i] = dp[i+pom.size()];
                    }
                    if(dp[i]) break;
                } 
            }
        }

        return dp[0];
 
    }
};
