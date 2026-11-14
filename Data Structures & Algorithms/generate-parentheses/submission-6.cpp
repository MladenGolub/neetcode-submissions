class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string trenutni;
        validna(0, 0, n, trenutni, ret);
        return ret;
    }

    void validna(int openN, int closedN, int n, string trenutni, vector<string>& ret) {
        if(openN == closedN && openN == n) {
            ret.push_back(trenutni);
            return;
        }

        if(openN < n) {
            trenutni.push_back('(');
            validna(openN + 1, closedN, n, trenutni, ret);
            trenutni.pop_back();
        }

        if(closedN < openN) {
            trenutni.push_back(')');
            validna(openN, closedN + 1, n, trenutni, ret);
            trenutni.pop_back();
        }
    }
};
