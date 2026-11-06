class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<string> stek;
        
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                stek.push(tokens[i]);
            } else {
                int b1 = stoi(stek.top());
                stek.pop();
                int b2 = stoi(stek.top());
                stek.pop();
                int rez;
                if(tokens[i] == "+") {
                    rez = b2 + b1;
                } else if(tokens[i] == "-") {
                    rez = b2 - b1;
                } else if(tokens[i] == "*") {
                    rez = b2 * b1;
                } else {
                    rez = b2 / b1;
                }
                stek.push(to_string(rez));
            }
        }

        return stoi(stek.top());

    }//dobijam niz koji treba da predstavlja stek
};
