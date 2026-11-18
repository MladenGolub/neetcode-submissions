class Solution {

    struct GraphNode {
        int val;
        unordered_map<int, GraphNode*> neighbours;
        GraphNode(int val) : val(val) {}
    };

public:

    bool dfs(GraphNode* root, int finish, vector<vector<int>>& dp) {
        if(root->val == finish) {
            return true;
        }

        if(dp[root->val][finish] != -1) {
            return dp[root->val][finish] == 1 ? true : false;
        } 

        for(auto it = root->neighbours.begin(); it != root->neighbours.end(); ++it) {
            if(dfs(it->second, finish, dp)) {
                dp[root->val][finish] = 1;
                return true; 
            }
        }

        dp[root->val][finish] = 0;
        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ret;
        
        vector<vector<int>> dp(numCourses, vector<int>(numCourses, -1));

        vector<GraphNode*> nodes(numCourses, nullptr);

        for(int i = 0; i < numCourses; i++) {
            nodes[i] = new GraphNode(i);
        }

        for(auto& pre : prerequisites) {
            nodes[pre[0]]->neighbours[pre[1]] = nodes[pre[1]];
        }

        for(auto& que : queries) {
            //treba mi neki backtrack da vidim da li su ova 2 cvora povezana, jer od jednog cvora moze biti vise putanja
            if(dfs(nodes[que[0]], que[1], dp)) {
                ret.push_back(true);
            } else {
                ret.push_back(false);
            }
        }

        return ret;

    }
};