class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         
        vector<bool> dp(s.size(), false);

        dp[s.size()] = true;

        cout << dp[s.size()] << endl;

        for(int i = s.size()-1; i >= 0; i--) {
            int pronadjen = 0;
            string pom;
            for(int j = 0; j < wordDict.size(); j++) {
                if(wordDict[j].size() <= s.size() - i) {
                    pom = s.substr(i, wordDict[j].size());
                    if(pom == wordDict[j]) {
                        dp[i] = dp[i+pom.size()];
                    }   
                    if(dp[i] == true) break; 
                }
            }
        }
        
        return dp[0];
    }
};
