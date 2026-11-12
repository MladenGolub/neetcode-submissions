class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size() > s2.size()) return false;

        int cnt1[26] = {0};
        int cnt2[26] = {0};

        int n = s1.size();

        for(int i = 0; i < n; i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }

        int matches = 0;

        for(int i = 0; i < 26; i++) {
            if(cnt1[i] == cnt2[i]) {
                matches++;
            }
        }//sada znamo koliko se slova poklapa po broju ponavlajnja u prvom prozoru u s2

        int l = 0;
        
        for(int r = n; r < s2.size(); r++) {
            if(matches == 26) return true;
            //ako se cnt svih karaktera u prozoru sirine n poklapa to je to nasli smo neku permutaciju u s2 od stringa s1

            int index = s2[r] - 'a';
            cnt2[index]++;
            if(cnt1[index] == cnt2[index]) {
                matches++;//ako smo dodali karakter u cnt2 i sada se cnt1 i cnt2 poklapaju za taj karakter onda uvecavamo broj pogodaka
            } else if(cnt1[index] + 1 == cnt2[index]) {
                //ako smo time sto smo azurirali cnt2 za taj karakter preterali moramo da smanjimo broj pogodaka
                matches--;
            }

            index = s2[l] - 'a';
            cnt2[index]--;//sada uklanjamo najlevlji karakter
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
