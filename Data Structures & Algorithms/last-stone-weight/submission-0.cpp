class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        if(stones.size() == 1) return stones[0];
        
        sort(stones.begin(), stones.end());//sada smo ih sortirali, dva najveca su na kraju
        int n = stones.size();

        while(n >= 1) {
        
            for(int s: stones) cout << s;
            cout << endl;
            if(stones.size() == 1) {
                return stones[0];
            }
            int stone1 = stones.back();
            stones.pop_back();
            int stone2 = stones.back();
            stones.pop_back();

            n = n - 2;

            
           

            if(stone1 > stone2) {
                stones.push_back(stone1 - stone2);
                n++;
            } else if (stone1 < stone2) {
                stones.push_back(stone2 - stone1);
                n++;
            }//ako su isti necemo nista uraditi samo smo ih obojicu izbacili i oni su se medjusobno unistili

            sort(stones.begin(), stones.end());
            cout << n << endl;
        
        }
        if(stones.size() == 0) return 0;
    }
};
