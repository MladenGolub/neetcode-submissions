class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> grane(n);

        if(n == 1) return {0};

        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            grane[e[0]]++;
            grane[e[1]]++;
        }

        queue<int> leaves;

        for(int i = 0; i < n; i++) {
            if(grane[i] == 1) leaves.push(i);
        }

        int remaining = n;
        while(remaining > 2) {
            int size = leaves.size();
            remaining -= size;
            for(int k = 0; k < size; k++) {
                int leaf = leaves.front(); leaves.pop();
                for(auto nei : adj[leaf]) {
                    grane[nei]--;
                    if(grane[nei] == 1) leaves.push(nei);
                }
            }
        }

        vector<int> res;
        while(!leaves.empty()) {res.push_back(leaves.front()); leaves.pop(); }
        return res;

    }
};