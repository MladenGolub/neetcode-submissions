class Solution {
public:
    string decodeString(string s) {
        
        stack<string> stek;

        string ret = "";

        string pom = "";

        string broj = "";

        for(char c : s) {
            if(c > 47 && c < 58) {
                broj += c;
            } else if(c == '[') {
                if(broj != "") stek.push(broj);
                broj = "";
                string seljak = string(1,c);
                stek.push(seljak);
            } else if(c == ']') {
                while(stek.top() != "[") {
                    pom = stek.top() + pom;
                    stek.pop();
                }
                stek.pop();
                int br = stoi(stek.top());
                stek.pop();
                string mnoz = pom;
                while(br > 1) {
                    pom = pom + mnoz;
                    br--;
                }
                stek.push(pom);
                pom = "";
            } else {
                if(broj != "") stek.push(broj);
                broj = "";
                string seljak = string(1,c);
                stek.push(seljak);
            }
        }

        while(!stek.empty()) {
            ret = stek.top() + ret;
            
            stek.pop();
        }

        return ret;
    }
};