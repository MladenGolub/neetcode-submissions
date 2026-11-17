class Solution {
public:
    int climbStairs(int n) {
        
        int prvi = 1;
        int drugi = 1;

        for(int i = 1; i < n; i++) {
            int pom = drugi + prvi;
            prvi = drugi;
            drugi = pom;
        }

        return drugi;
    }
};
