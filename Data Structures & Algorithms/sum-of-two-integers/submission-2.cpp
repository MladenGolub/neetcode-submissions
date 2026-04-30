class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        int ret = 0;
        for(int i = 0; i < 32; i++) {
            int az = (a>>i) & 1;
            int bz = (b>>i) & 1;
            int r = 0;

            if(az && bz && c) {
                r = 1;
                c = 1;
            } else if(!az && bz && c) {
                r = 0;
                c = 1;
            } else if(az && !bz && c) {
                r = 0;
                c = 1;
            } else if(!az && !bz && c) {
                r = 1;
                c = 0;
            } else if(az && bz && !c) {
                r = 0;
                c = 1;
            } else if(!az && bz && !c) {
                r = 1;
                c = 0;
            } else if(az && !bz && !c) {
                r = 1;
                c = 0;
            } else {
                r = 0;
                c = 0;
            }
            ret = ret | (r<<i);
        }
        return ret;
    }
};
