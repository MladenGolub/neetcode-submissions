class Solution {

    bool isPalindrome(string s) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if(s[i] != s[j]) {
                return false;
            }
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
                bool levi = isPalindrome(s.substr(i+1, j - i));
                bool desni = isPalindrome(s.substr(i, j - i));
                bool ret = levi || desni;
                cout << s.substr(i+1, j - i + 1) << endl;
                cout << s.substr(i, j - i);
                if(ret) cout << "tacno";
                return ret;
            }
        }

        return true;


    }
};