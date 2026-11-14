class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ret;
        vector<int> cur;

        dfs(1, n, k, cur, ret);

        return ret;

    }

    void dfs(int i, int n, int k, vector<int>& cur, vector<vector<int>>& ret) {
        if(i > n) {
            if(cur.size() == k) {
                ret.push_back(cur);
            }
            return;
        }

        cur.push_back(i);
        dfs(i + 1, n, k, cur, ret);
        cur.pop_back();
        dfs(i+1, n, k, cur, ret);
    
    }
};