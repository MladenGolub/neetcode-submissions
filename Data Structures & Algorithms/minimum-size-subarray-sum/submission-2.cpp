class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int l = 0;
        int r = 0;
        int suma = 0;
        int velPodniza = INT_MAX;

        while(l != nums.size() && r != nums.size()) {

            if(suma + nums[r] >= target) {
                int pom = r - l + 1;
                if(pom < velPodniza) velPodniza = pom;
                suma = suma - nums[l];
                l++;
            } else {
                suma = suma + nums[r];
                r++;
            }

        }

        return (velPodniza == INT_MAX) ? 0 : velPodniza;

    }
};