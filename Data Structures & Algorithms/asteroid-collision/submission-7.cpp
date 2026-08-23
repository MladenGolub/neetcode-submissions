class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> stek;

        if(asteroids.size() == 0) return stek;

        stek.push_back(asteroids[0]);

        for(int i = 1; i < asteroids.size(); i++) {
            int rez = 0;
            if(stek.empty() || stek.back() > 0 && asteroids[i] > 0 || stek.back() < 0 && asteroids[i] < 0) {
                stek.push_back(asteroids[i]);
            } else {
                rez = asteroids[i];
                while(!stek.empty() && ((stek.back() > 0 && rez < 0))) {
                    int pom = stek.back();
                    stek.pop_back();
                    
                    if(abs(pom) > abs(rez)) {
                        rez = pom;
                        
                    } else if(abs(pom) < abs(rez)) {
                        //rez samo ostaje rez
                    } else {
                        rez = 0;
                        break;
                    }
                }
                if (rez != 0) stek.push_back(rez);
            }
        }

        return stek;
    }
};