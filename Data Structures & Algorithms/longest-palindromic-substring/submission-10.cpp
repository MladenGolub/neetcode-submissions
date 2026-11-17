class Solution {
public:
    string longestPalindrome(string s) {

        string najduziNeparni = "";
        string najduziParni = "";

        for(int i = 0; i < s.size(); i++) {
            string pom = longestPali(i, i, s);
            if(pom.size() > najduziNeparni.size()) najduziNeparni = pom;
        
            pom = longestPali(i, i+1, s);
            if(pom.size() > najduziParni.size()) najduziParni = pom;
        }

        return (najduziNeparni.size() > najduziParni.size()) ? najduziNeparni : najduziParni;

    }

    string longestPali(int i, int j, string s) {
        string pom = "";
        while(i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }

        return s.substr(i+1, j - i - 1);

    }
    
};
