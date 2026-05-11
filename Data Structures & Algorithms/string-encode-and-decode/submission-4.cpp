class Solution {
public:

    string encode(vector<string>& strs) {
        string ret = "";
        for(int i = 0; i < strs.size(); i++) {
            ret += strs[i];
            ret += ';';
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        string::iterator it;
        string pom = "";
        string razmak = "";
        for(it = s.begin(); it != s.end(); it++) {
            if(*it == ';') {
                ret.push_back(pom);
                pom = "";
            } else {
                pom += *it;
            }
            std::cout << *it;
        }   
             
            
            return ret; 
        }

};
