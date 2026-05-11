class Solution {
public:
    bool isPalindrome(string s) {
        
        string spojen = "";
        for(int i = 0; i < s.size(); i++) {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] >= '0' && s[i] <= '9') {
                spojen += s[i];
            }
        }//string ce biti bez razmaka, i trebalo bi da se cita isto spreda kao i od pozadi
        cout << spojen;
        for(int i = 0, j = spojen.size() - 1; i < spojen.size() / 2; i++, j--) {
            if(std::tolower(spojen[i]) != std::tolower(spojen[j])) {
                return false;
            }
        }

        return true;

    }
};
