class Solution {
    unordered_map<string, vector<string>> adj;
    unordered_set<string> visited;

    void dfs(const string& email, vector<string>& comp) {
        visited.insert(email);
        comp.push_back(email);
        for (const string& nei : adj[email])
            if (!visited.count(nei)) dfs(nei, comp);
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;

        for (auto& acc : accounts) {
            const string& first = acc[1];
            for (int i = 1; i < acc.size(); i++) {
                emailToName[acc[i]] = acc[0];
                if (i > 1) {                       // poveži sa prvim emailom
                    adj[first].push_back(acc[i]);
                    adj[acc[i]].push_back(first);
                }
            }
        }

        vector<vector<string>> res;
        for (auto& [email, name] : emailToName) {
            if (visited.count(email)) continue;
            vector<string> comp;
            dfs(email, comp);
            sort(comp.begin(), comp.end());
            comp.insert(comp.begin(), name);       // ime ide prvo
            res.push_back(comp);
        }
        return res;
    }
};