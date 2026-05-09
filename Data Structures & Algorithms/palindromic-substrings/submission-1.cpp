class Solution {
public:
    int countSubstrings(string s) {
        int ret = 0;
        for(int i = 0; i<s.size(); i++) {
            ret += palis(i, i, s);
            ret += palis(i, i+1, s);
        }

        return ret;

    }

    int palis(int i, int j, string s) {
        int cnt = 0;
        while(i >= 0 && j < s.size() && s[i]==s[j]) {
            i--;
            j++;
            cnt++;
        }
        return cnt;
    }
};
