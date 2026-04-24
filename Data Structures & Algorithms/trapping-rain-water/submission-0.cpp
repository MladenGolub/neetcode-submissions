class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int vode = 0;
        for(int i = 0; i < height.size(); i++) {
            int maxLeva = height[l];
            int maxDesna = height[r];
            while(l < i) {
                if(height[l] > maxLeva) {
                    maxLeva = height[l];
                }
                l++;
            }
            while(i < r) {
                if(height[r] > maxDesna) {
                    maxDesna = height[r];
                } 
                r--;
            }        
            int naIvode = min(maxLeva, maxDesna) - height[i];
            if(naIvode < 0) {
                vode += 0;
            } else {
                vode += naIvode;
            }
            l = 0;
            r = height.size()-1;
        }

        return vode;
    }
};
