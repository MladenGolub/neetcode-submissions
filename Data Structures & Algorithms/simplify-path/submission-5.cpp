class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> stek;

        string ret = "/";//mora poceti ovako

        string pom = "";
        path = path.substr(1, path.size() - 1);
        for(char c: path) {
            if(pom == "") {
                if(c == '/') {}
                else if(c == '.') {
                    pom += c;
                } else {
                    pom += c;
                }
                
            }
            else if(pom == ".") {
                if(c == '.')
                    { pom += c; }
                else if(c == '/') {
                    pom = "";
                } else {
                    pom += c;
                }
                //racunam da ne moze doci bilo sta posle tacke sem nove tacke ili / za kraj kao samo . trenutni direktorijum
            }
            else if(pom == "..") {
                if(c == '.') {
                    pom += c;
                } else if(c == '/') {
                    pom = "";
                    if(!stek.empty()) {
                        stek.pop();
                    }
                } else {
                    pom += c;
                }
            }
            else {
                if(c == '/') {
                    stek.push(pom);
                    pom = "";
                } else {
                    pom += c;
                }
            } 
        }

        if(pom == "..") {
            if(!stek.empty()) {
                stek.pop();
                pom = "";
            }
        }
        if(pom != "" && pom != ".") stek.push(pom);

        vector<string> pomocni;

        while(!stek.empty()) {
            pomocni.push_back(stek.top());
            stek.pop();
        }

        for(int i = pomocni.size()-1; i >= 0; i--) {
            ret += pomocni[i];
            if(i != 0) ret += '/';
        }

        return ret;

    }
};