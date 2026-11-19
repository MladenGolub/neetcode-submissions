class Solution {
public:
    long long minEnd(int n, int x) {

        long long res = x;
        int cnt = 1;

        while(cnt < n) {
            res = res + 1;
            res = res | x;
            cnt++;
        }

        return res;

    }
};