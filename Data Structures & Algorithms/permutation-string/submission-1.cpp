class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()) return false;
        
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);

        for(int i = 0; i < s1.size(); i++) {
            cnt1[s1[i] - 'a'] += 1;
            cnt2[s2[i] - 'a'] += 1;
        }

        int n = s1.size();

        int matches = 0;

        for(int i = 0; i < 26; i++) {
            if(cnt1[i] == cnt2[i]) {
                matches++;
            }
        }

        int l = 0;
        
        for(int r = n; r < s2.size(); r++) {
            if(matches == 26) return true;

            int index = s2[r] - 'a'; 
            cnt2[index]++;//dodajem karakter sledeci u prozoru koji smo pomerili
            
            if(cnt1[index] == cnt2[index]) {
                matches++;
            } else if(cnt1[index] + 1 == cnt2[index]) {
                matches--;
            }   

            index = s2[l] - 'a';
            cnt2[index]--;
            if(cnt1[index] == cnt2[index]) {
                matches++;
            } else if(cnt1[index] - 1 == cnt2[index]) {
                matches--;
            }
            l++;
        }

        return matches == 26;

    }
};
