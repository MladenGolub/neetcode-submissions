class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int minKG = 1;
        int maxKG = *max_element(piles.begin(), piles.end());

        int retKG = maxKG;

        while(minKG <= maxKG) {

            int mid = minKG + (maxKG - minKG) / 2;
            long long hours = 0;

            for(int i = 0; i < piles.size(); i++) {
                hours += piles[i] / mid;
                if(piles[i] % mid) hours++;
            }

            if(hours > h) {
                minKG = mid + 1;
            } else {
                maxKG = mid - 1;
                retKG = mid;
            }
        } 

        return retKG;

    }
};
