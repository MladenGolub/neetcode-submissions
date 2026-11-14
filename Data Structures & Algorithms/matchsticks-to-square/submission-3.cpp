class Solution {

    bool dfs(vector<int>& matches, vector<int>& sides, int index, int length) {
        if(index == matches.size()) {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];;
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
        int maxEl = *max_element(matchsticks.begin(), matchsticks.end());
        if(totalLength%4 != 0) return false;

        int length = totalLength/4;

        if(maxEl > length) return false;

        vector<int> sides(4, 0);

        return dfs(matchsticks, sides, 0, length);

    }
};