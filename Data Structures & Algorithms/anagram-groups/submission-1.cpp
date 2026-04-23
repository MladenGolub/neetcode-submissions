class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;

        for(auto &s : strs) {
            string st(26,0);

            for(auto &g : s) {
                st[g-'a']++;
            }

            mp[st].push_back(s);
        }//koristimo kao kljuc string koji ce se sastojati iz prebrojanih slova, koja se nalaze u nizu

        vector<vector<string>> ans;

        for(auto &s: mp) {
            ans.push_back(s.second);
        }

        return ans;

    }
};
