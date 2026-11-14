class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        stack<string> stek;
        vector<string> res;
    
        validna(0, 0, stek, res, n);
        return res;
    }


    void validna(int openN, int closedN, stack<string> stek, vector<string>& res, int n) {//proveravam da li je trenutni string validan, ako jeste onda cu ga ili nastaviti dalje ili staviti u res 

        if(openN == closedN && openN == n) {
            string pom = "";
            int gr = stek.size();
            for(int i = 0; i < gr; i++) {
                pom.insert(0, stek.top());
                stek.pop();
            }
            res.push_back(pom);
            return;
        }

        if(openN < n) {
            stek.push("(");
            validna(openN+1, closedN, stek, res, n);
            stek.pop();
        }

        if(closedN < openN) {
            stek.push(")");
            validna(openN, closedN+1, stek, res, n);
            stek.pop();
        }
    }
};
 