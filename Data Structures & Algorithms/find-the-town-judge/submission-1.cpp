class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> trustInPeople(n+1, -1);
        vector<int> peopleTrust(n + 1, 0);

        for(int i = 0; i < trust.size(); i++) {
            trustInPeople[trust[i][0]] = 1;
            peopleTrust[trust[i][1]] += 1;
        }

        for(int i = 1; i < n+1; i++) {
            if(trustInPeople[i] == -1 && peopleTrust[i] == n-1) return i;
        }

        return -1; 

    }
};