class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() >= t.size()) {
            for(int i = 0; i < s.size(); i++) {
                int pom = t.find(s[i]);
                if(pom == -1) {
                    return false;
                } else {
                    t[pom] = '0';
                }
            }
        } else {
            for(int i = 0; i < t.size(); i++) {
                int pom = s.find(t[i]);
                if(pom == -1) {
                    return false;
                } else {
                    s[pom] = '0';
                }
            }
        }
        

        return true;

    }
};
