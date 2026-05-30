class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string pom = "";
        string pom1 = strs[0];

        for(int i = 1; i < strs.size(); i++) {
            int j = 0;
            while(j < min(pom1.size(), strs[i].size())) {
                if(pom1[j] != strs[i][j]) {
                    break;
                } 
                pom += pom1[j];
                j++;
                
            }
            pom1 = pom;
            pom = "";
        }

        return pom1;
    }
};