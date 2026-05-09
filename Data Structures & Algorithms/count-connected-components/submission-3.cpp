class Solution {

    // set<int> visited;
    //map<int, vector<int>> mapa;

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> mapa(n);
        vector<bool> visited(n, false);

        for(auto& e: edges) {
            mapa[e[1]].push_back(e[0]);
            mapa[e[0]].push_back(e[1]);//dodajemo u cvorove njihove susede
        }

        int res = 0;

        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                dfs(i, visited, mapa);
                res++;
            }
        }

        return res;

    }

    void dfs(int node, vector<bool>& visited, vector<vector<int>>& mapa) {
        //if(visited[node]) return;//ako smo ga vec obisli nema potrebe opet
        visited[node] = true;
        for(int i = 0; i < mapa[node].size(); i++) {
            if(!visited[mapa[node][i]]) dfs(mapa[node][i], visited, mapa);
        }

    }
};
