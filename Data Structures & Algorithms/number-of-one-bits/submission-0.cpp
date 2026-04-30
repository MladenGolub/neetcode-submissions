class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n != 0) {
            int pom = n & 1;
            n = n >> 1;
            if(pom) cnt++;
        }

        return cnt;

    }
};
