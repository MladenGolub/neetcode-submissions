class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        //vector<int> minLeftRight;

        int maksimum = 0;
        for(int i = 0; i < height.size(); i++) {
            maxLeft[i] = maksimum;
            if(height[i] > maksimum) {
                maksimum = height[i];
            }
        }
        maksimum = 0;
        for(int i = height.size()-1; i >= 0; i--) {
            maxRight[i] = maksimum;
            if(height[i] > maksimum) {
                maksimum = height[i];
            }
        }

        int vode = 0;
        for(int i = 0; i < height.size(); i++) {
            int pom = min(maxLeft[i], maxRight[i]) - height[i];
            if(pom < 0) {
                vode += 0;
            } else {
                vode += pom;
            }
        }
        return vode;
    }
    
};
