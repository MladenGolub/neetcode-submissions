class Solution {
public:
    // int climbStairs(int n) {
    //     if(n == 0) return 0;

    //     int leviBr = dfs(n, 1);
    //     int desniBr = dfs(n, 2);//na levo idem uvek sa korakom 1, a na desno sa korakom 2

    //     return leviBr + desniBr;

    // }

    // int dfs(int n, int zbir) {
    //     if(zbir == n) {
    //         return 1;
    //     }
    //     if(zbir > n) {
    //         return 0;
    //     }

    //     int leviBr = dfs(n, zbir+1);
    //     int desniBr = dfs(n, zbir+2);

    //     return leviBr+desniBr;
    // }

    int climbStairs(int n) {
        
        int one = 1;
        int two = 1;

        for(int i = 0; i < n-1; i++) {
            int c = one + two;
            one = two;
            two = c;
        }

        return two;

    }
};
