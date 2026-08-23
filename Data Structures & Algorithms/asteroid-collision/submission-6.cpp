class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> stek;
        
        vector<int> ret;

        if(asteroids.size() == 0) return ret;

        stek.push(asteroids[0]);

        for(int i = 1; i < asteroids.size(); i++) {
            int rez = 0;
            if(stek.empty() || stek.top() > 0 && asteroids[i] > 0 || stek.top() < 0 && asteroids[i] < 0) {
                stek.push(asteroids[i]);
            } else {
                rez = asteroids[i];
                while(!stek.empty() && ((stek.top() > 0 && rez < 0))) {
                    int pom = stek.top();
                    stek.pop();
                    
                    if(abs(pom) > abs(rez)) {
                        rez = pom;
                        
                    } else if(abs(pom) < abs(rez)) {
                        //rez samo ostaje rez
                    } else {
                        rez = 0;
                        break;
                    }
                }
                if (rez != 0) stek.push(rez);
            }
        }

        while(!stek.empty()) {
            ret.push_back(stek.top());
            stek.pop();
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};