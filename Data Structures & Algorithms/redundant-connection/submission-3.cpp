class Solution {

    vector<vector<int>> adj;

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        adj.resize(n+1);
        

        for(auto& edge : edges) {
            int u = edge[0]; 
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            vector<bool> visit(n+1, false);

            if(dfs(u, -1, visit)) return {u, v};
        }

        return {};
    }


    bool dfs(int node, int prev, vector<bool>& visit) {
        if(visit[node]) return true;
        visit[node] = true;
        for(int nei : adj[node]) {
            if(nei == prev) continue;
            if(dfs(nei, node, visit)) return true;
        }
        return false;
    }

};
