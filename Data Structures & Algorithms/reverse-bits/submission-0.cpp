class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t pom = 0;
        int cnt = 0;
        while(n != 0) {
            int pom2 = n & 1;
            n = n >> 1;
            int pom3 = pom2 << (31 - cnt);
            cnt++;
            pom = pom ^ pom3;
        }

        return pom;
    }
};
