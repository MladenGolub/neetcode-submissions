class Solution {//optimizovan prostor
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p .size();
        vector<bool> dp(n + 1, false);//cuvam vektor duzine paterna
        vector<bool> nextDp(n + 1, false);
        dp[n] = true;
        nextDp[n] = true;

        for(int i = m; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                bool match = s[i] == p[j] || p[j] == '.';

                if((j + 1) < n && p[j+1] == '*') {//ako nam nailazi karakter sa zvezdom, pravimo poseban uslov
                    
                    if(match) {
                        nextDp[j] = dp[j] || nextDp[j+2];
                    } else {
                        nextDp[j] = nextDp[j+2];
                    }

                } else if(match) {
                    nextDp[j] = dp[j+1];
                }
            }
            dp = nextDp;
            nextDp.assign(n + 1, false);
        }

        return dp[0];
    }
};
