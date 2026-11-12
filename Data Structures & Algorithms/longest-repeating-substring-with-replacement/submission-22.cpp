class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int count[26] = {0};

        int maxF = 0;
        int l = 0;
        int res = 0;

        for(int r = 0; r < s.size(); r++) {
            maxF = max(maxF, ++count[s[r] - 'A']);

            if((r - l + 1) - maxF > k) {
                count[s[l] - 'A']--;
                l++;
            } 

            res = max(res, r - l + 1);
        }

        return res;

    }
};
