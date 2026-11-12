class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        set<string> skup;
        sort(s1.begin(), s1.end());
        skup.insert(s1);

        int n = s1.size();

        for(int i = 0; i < s2.size() && (i+n-1) < s2.size(); i++) {
            string pom = s2.substr(i, n);
            sort(pom.begin(), pom.end());
            if(skup.count(pom)) {
                return true;
            }
        }
        return false;
    }
};
