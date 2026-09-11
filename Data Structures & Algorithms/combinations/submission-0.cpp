class Solution {

    void dfs(int i, int n, int k, vector<int>& cur, vector<vector<int>>& res) {
        if(i > n) {
            if(cur.size() == k) {
                res.push_back(cur);
            }
            return;
        }
        cur.push_back(i);
        dfs(i+1, n, k, cur, res);
        cur.pop_back();
        dfs(i+1, n, k, cur, res);
    }

public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res;
        vector<int> cur;

        dfs(1, n, k, cur, res);

        return res;

    }
};