class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int l = 0;
        int r = heights.size()-1;
        int maxWater = 0;
        while(l < r) {
            maxWater = max(maxWater, (r-l) * min(heights[r], heights[l]));
            if(heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return maxWater;

    }
};
