class Solution {
public:
    int climbStairs(int n) {
        
        int prvi = 0;
        int drugi = 1;

        for(int i = 0; i < n; i++) {
            int pom = prvi + drugi;
            prvi = drugi;
            drugi = pom;
        }

        return drugi;

    }
};
