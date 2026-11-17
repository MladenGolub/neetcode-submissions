class Solution {
public:
    int tribonacci(int n) {
        
        int nulti = 0;
        int prvi = 1;
        int drugi = 1;

        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return nulti + prvi;
        if(n == 3) return nulti + prvi + drugi;

        for(int i = 3; i <= n; i++) {
            int pom = nulti + prvi + drugi;
            nulti = prvi;
            prvi = drugi;
            drugi = pom;
        }

        return drugi;

    }
};