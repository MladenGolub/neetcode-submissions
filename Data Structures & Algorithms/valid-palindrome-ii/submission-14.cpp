class Solution {

    bool isPalindrome(string s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {

        for(int i = 0, j = s.size()-1; i < j;) {
            if(s[i] == s[j]) {
                i++;
                j--;
            } else {
                bool levi = isPalindrome(s, i + 1, j);
                bool desni = isPalindrome(s, i, j - 1);
                return levi || desni;
            }
        }

        return true;


    }
};