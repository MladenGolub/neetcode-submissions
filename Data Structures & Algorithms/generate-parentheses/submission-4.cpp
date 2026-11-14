class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        stack<string> stek;
        validna(0, 0, n, stek, ret);
        return ret;
    }

    void validna(int openN, int closedN, int n, stack<string> stek, vector<string>& ret) {
        if(openN == closedN && openN == n) {
            string pom = "";
            int size = stek.size();
            for(int i = 0; i < size; i++) {
                pom.insert(0, stek.top());
                stek.pop();
            }
            ret.push_back(pom);
            return;
        }

        if(openN < n) {
            stek.push("(");
            validna(openN + 1, closedN, n, stek, ret);
            stek.pop();
        }

        if(closedN < openN) {
            stek.push(")");
            validna(openN, closedN + 1, n, stek, ret);
            stek.pop();
        }
    }
};
