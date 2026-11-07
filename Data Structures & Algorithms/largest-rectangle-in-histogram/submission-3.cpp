class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<pair<int, int>> stek;

        int maxArea = 0;
        int cnt = 0;

        for(int i = 0; i < heights.size(); i++) {
            while(!stek.empty() && (stek.top().first > heights[i])) {
                int pom = stek.top().first * (i - stek.top().second);//mnozim visinu koja se nalazi na steku, sa udaljenoscu do prvog koji je nizi od njega
                cnt = i - stek.top().second;
                stek.pop();
                if(maxArea < pom) maxArea = pom;
            }
            stek.push({heights[i], i - cnt});
            cnt = 0;
        }

        while(!stek.empty()) {
            int pom = stek.top().first * (heights.size() - stek.top().second);
            stek.pop();
            if(maxArea < pom) maxArea = pom;
        }

        return maxArea;

    }
};
