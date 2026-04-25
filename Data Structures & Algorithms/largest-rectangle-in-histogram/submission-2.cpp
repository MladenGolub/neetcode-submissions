class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        //ako redom guram na stek velicine, i skidam ih samo ako naidjem na velicinu manju od te koja je trenutno na steku,
        //a ako je velicina koja nailazi vec manja od one na steku onda skidam staru sa steka sve dok ne naidjem na neku koja je manja od nje, i onda novu stavljam na stek

        stack<pair<int,int>> st;//cuvam par na steku, koja je visina, i na kom je indeksu

        int maxArea = 0;
        int cnt = 0;
        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && st.top().first > heights[i]) {
                int pom = st.top().first * (i - st.top().second);//ovo je najveca tr povrsina
                if(maxArea < pom) maxArea = pom;
                cnt = i - st.top().second;
                st.pop();//skidam sa steka, sve dok na njemu postoji veca vrednost od mene
            }
            st.push({heights[i], i-cnt});
            cnt = 0;
            //if((heights[i]) > vertP) vertP = heights[i];
        }

        while(!st.empty()) {
            int pom = st.top().first * (heights.size() - st.top().second);
            st.pop();
            if(pom > maxArea) maxArea = pom;
        }

        return maxArea;
    }
};
