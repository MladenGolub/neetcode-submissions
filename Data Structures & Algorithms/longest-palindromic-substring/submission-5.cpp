class Solution {
public:
    string longestPalindrome(string s) {

        string najduziNeparni = "";
        string najduziParni = "";

        for(int i = 0; i < s.size(); i++) {
            string pom = longestPali(i, i, s);
            if(pom.size() > najduziNeparni.size()) najduziNeparni = pom;
        }

        for(int i = 0; i < s.size()-1; i++) {
            string pom = longestPali(i, i+1, s);
            if(pom.size() > najduziParni.size()) najduziParni = pom;
        }

        return (najduziNeparni.size() > najduziParni.size()) ? najduziNeparni : najduziParni;

    }

    string longestPali(int i, int j, string s) {
        string pom = "";
        while(i >= 0 && j < s.size()) {

            if(s[i] == s[j]) {
                if(i != j) pom = s[i] + pom + s[j];
                else pom = s[i];
                i--;
                j++;
            } else {
                break;
            }
        }

        return pom;

    }
    
};
