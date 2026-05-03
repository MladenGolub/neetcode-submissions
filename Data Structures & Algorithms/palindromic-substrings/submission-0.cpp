class Solution {
public:
    int countSubstrings(string s) {
        
        int cnt = 0;
        int l = 0;
        int r = 0;
        for(int i = 0; i < s.size(); i++) {
            l = i;
            r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                cnt++;
                l--;
                r++;
            }

            l = i;
            r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                cnt++;
                l--;
                r++;
            }
        }

        return cnt;

    }
};
