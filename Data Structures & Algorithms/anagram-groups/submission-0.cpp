class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        std::map<vector<int>, vector<string>> res;

        for(string s: strs) {
            vector<int> count(26, 0);

            for(char c: s) {
                count[c - 'a']++;
            }
            res[count].push_back(s);
        }

        vector<vector<string>> result;

        for (auto it = res.begin(); it != res.end(); ++it) {
            result.push_back(it->second);
        }

        return result;

    }
};
