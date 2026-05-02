class Solution {

    set<int> visited;
    map<int, vector<int>> mapa;

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        for(int i = 0; i < n; i++) {
            mapa[i] = vector<int>();
        }

        for(auto& e: edges) {
            mapa[e[1]].push_back(e[0]);
            mapa[e[0]].push_back(e[1]);//dodajemo u cvorove njihove susede
        }

        int cnt = 1;
        int prev = 0;

        for(int i = 0; i < n; i++) {
            dfs(i);//pocinjem od 0
            if(visited.size() == n) {
                break;
            }
            if(prev < visited.size()) {
                cnt++;
                prev = visited.size();
            }
        }

        return cnt;

    }

    void dfs(int node) {

        if(visited.find(node) != visited.end()) {
            return;
        }

        visited.insert(node);
        for(int i = 0; i < mapa[node].size(); i++) {
            dfs(mapa[node][i]);
        }

    }
};
