class Solution {

    map<int, vector<int>> mapa;
    set<int> visited;

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() < n-1) return false; 

        for(int i = 0; i < n; i++) {
            mapa[i] = vector<int>();
        }

        for(auto& e : edges) {
            mapa[e[0]].push_back(e[1]);//dodajemo sve grane u vektor za odredjeni cvor
            mapa[e[1]].push_back(e[0]);
        }
 
        // for(int i = 0; i < n; i++) {
        //     if(!dfs(i, -1)) return false;
        // }

        return dfs(0, -1) && n == visited.size();

        return true;

    }

    bool dfs(int node, int prev) {
        if(visited.find(node) != visited.end()) { return false; }

        visited.insert(node);

        for(int i = 0; i < mapa[node].size(); i++) {
            if(mapa[node][i] != prev) {
                if(!dfs(mapa[node][i], node)) return false;    
            } else {
                continue;
            }
            
        }
        
        return true;
        
    }
};
