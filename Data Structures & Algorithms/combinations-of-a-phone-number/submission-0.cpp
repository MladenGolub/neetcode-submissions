class Solution {
    vector<string> res;

    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    vector<string> letterCombinations(string digits) {
        

        if(digits.size() != 0) {
            dfs(0, digits, "");
        }
    
        return res;
    }

    void dfs(int i, string digits, string curr) {

        if(curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }
        
        string chars = digitToChar[digits[i] - '0'];
        for(char c: chars) {
            dfs(i+1, digits, curr + c);
        }

    }
};
