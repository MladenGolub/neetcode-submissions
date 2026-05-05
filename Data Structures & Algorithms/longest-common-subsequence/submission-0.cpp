class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp2(text1.size()+1, vector<int>(text2.size()+1, 0));//dodam jos jedan red i jos jednu kolonu, i u njih upisem 0 da bih znao kada dodjem do kraja

        for(int i = text1.size()-1; i >= 0; i--) {
            for(int j = text2.size()-1; j >= 0; j--) {
                if(text1[i] == text2[j]) dp2[i][j] = 1 + dp2[i+1][j+1];//ako su jednaki dodajem ono sto pise na dijagonali vec
                else dp2[i][j] = max(dp2[i+1][j], dp2[i][j+1]);
            }
        }

        return dp2[0][0];

    }
};
