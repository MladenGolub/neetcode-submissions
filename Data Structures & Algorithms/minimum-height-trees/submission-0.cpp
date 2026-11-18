class Solution {
private:

    vector<vector<int>> adj;

    int dfs(int node, int parent) {
        int h = 0;
        for(int nei : adj[node]) {
            if(nei == parent) {
                continue;
            }
            h = max(h, 1 + dfs(nei, node));
        }

        return h;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        adj.resize(n);

        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int minHeight = n;

        vector<int> res;
        for(int i = 0; i < n; i++) {
            int curHeight = dfs(i, -1);
            if(curHeight == minHeight) {
                res.push_back(i);
            } else if(curHeight < minHeight) {
                res = {i};
                minHeight = curHeight;
            }
        }

        return res;


    }
};