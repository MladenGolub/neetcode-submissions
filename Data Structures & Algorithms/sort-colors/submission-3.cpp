class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3);//imam vektor sa 3 pozicije i racunam za 3 boje i koristim count sort
        
        for(int boja: nums) {
            cnt[boja]++;
        }

        for(int i = 0, j = 0; i < nums.size() && j<cnt.size(); i++) {
            // if(cnt[j] > 0) {
            //     nums[i] = j;
            //     cnt[j]--;
            // }else{
            // j++;
            // i--;
            // }
            while(cnt[j] > 0) {
                nums[i] = j;
                cnt[j]--;
                i++;
            }
            i--;
            j++;
        }
        

    }
};