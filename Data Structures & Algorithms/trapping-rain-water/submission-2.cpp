class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int res = 0;
        int maxL = height[l];
        int maxR = height[r];

        while(l < r) {
            if(maxL <= maxR) {
                l++;
                maxL = max(maxL, height[l]);
                res += maxL - height[l];
            } else {
                r--;
                maxR = max(maxR, height[r]);
                res += maxR - height[r];
            }
        }

        return res;
    }
};
