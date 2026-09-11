class Solution {

    bool dfs(vector<int>& matches, vector<int>& sides, int index, int length) {
        if(index == matches.size()) {
            return true;
        }

        for(int i = 0; i < 4; i++) {
            if(sides[i] + matches[index] <= length) {
                sides[i] += matches[index];
                if(dfs(matches, sides, index+1, length)) return true;
                sides[i] -= matches[index];
            }
            if(sides[i] == 0) break;
        }

        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        
        int totalLength = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(totalLength%4 != 0) return false;

        int length = totalLength/4;
        vector<int> sides(4, 0);
        sort(matchsticks.rbegin(), matchsticks.rend());

        return dfs(matchsticks, sides, 0, length);

    }
};