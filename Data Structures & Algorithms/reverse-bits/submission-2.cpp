class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t pom = 0;
        int cnt = 0;
        while(cnt < 32) {
            uint32_t bit = (n >> cnt) & 1;
            pom += (bit << (31 - cnt));
            cnt++;
        }

        return pom;
    }
};
