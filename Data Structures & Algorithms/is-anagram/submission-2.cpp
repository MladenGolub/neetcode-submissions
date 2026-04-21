class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() == t.size()) {
            for(int i = 0; i < s.size(); i++) {
                int pom = t.find(s[i]);
                if(pom == -1) {
                    return false;
                } else {
                    t[pom] = '0';
                }
            }
        } else {
            return false;
        }
        

        return true;

    }
};
