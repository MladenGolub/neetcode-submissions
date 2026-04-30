class Solution {

    vector<vector<string>> res;

public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        backtrack(0, 0, s, curr);
        return res;
    }

    void backtrack(int j, int i, string& s, vector<string>& curr) {

        if(i >= s.size()) {
            if(i == j) {
                res.push_back(curr);
            }
            return;
        }

        if(isPalindrom(s.substr(j, i-j+1))) {//ako jeste palindrom, probacemo dalje da guramo
            curr.push_back(s.substr(j, i-j+1));
            backtrack(i+1, i+1, s, curr);
            curr.pop_back();
        } 

        backtrack(j, i+1, s, curr);
        
}

    bool isPalindrom(string s) {
        for(int i = 0, j = s.size()-1; i < j; i++, j--) {
            if(s[i] != s[j]) return false;
        }
        return true;
    }
};
