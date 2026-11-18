class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();

        vector<bool> dp(n + 1, false);

        dp[n] = true;

        for(int i = n-1; i>=0; i--) {
            for(int j = 0; j < wordDict.size(); j++) {
                if(wordDict[j].size() + i <= n) {
                    string pom = s.substr(i, wordDict[j].size());
                    if(pom == wordDict[j]) {
                        dp[i] = dp[i + pom.size()];
                    }
                    if(dp[i]) break;
                } 
            }
        }

        return dp[0];

    }
};
