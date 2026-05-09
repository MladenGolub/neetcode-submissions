class Solution {
public:
    string longestPalindrome(string s) {
        
        int resStart = 0;
        int resLen = 0;
        int l = 0;
        int r = 0;

        for(int i = 0; i < s.size(); i++) {
            l = i;
            r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                if((r-l+1) > resLen) {
                    resStart = l;
                    resLen = r - l + 1; 
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                if((r-l+1) > resLen) {
                    resStart = l;
                    resLen = r - l + 1; 
                }
                l--;
                r++;
            }
        }

        return s.substr(resStart, resLen);

    }

};
