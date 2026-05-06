class Solution {
public:
    int minDistance(string word1, string word2) {
        
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));

        for(int i = 0; i <= word1.size(); i++) {
            dp[i][word2.size()] = word1.size() - i;
        }

        for(int i = 0; i <= word2.size(); i++) {
            dp[word1.size()][i] = word2.size() - i;
        }

        for(int i = word1.size()-1; i >= 0; i--) {
            for(int j = word2.size()-1; j>= 0; j--) {
                if(word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = 1 + min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1]));
                }
            }
        }

        return dp[0][0];

    }
};
