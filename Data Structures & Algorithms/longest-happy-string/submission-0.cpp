class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
                
        string happy = "";

        int cnt = 0;//koliko imamo karaktera

        auto cmp = [](pair<char, int> a, pair<char, int> b){
            if(a.second != b.second) return a.second < b.second;
            return a.first > b.first;
        };

        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(cmp)> pq;

        if(a > 0) pq.push({'a', a});
        if(b > 0) pq.push({'b', b});
        if(c > 0) pq.push({'c', c});

        while(a > 0 || b > 0 || c > 0) {

            auto pom = pq.top();
            pq.pop();

            if(happy.size() >= 2) {
                string pomocni = happy.substr(happy.size() - 2, 2);
                if(pomocni[0] == pom.first && pomocni == string(2, pom.first)) {
                    if(pq.empty()) return happy;
                    auto drugi = pq.top();
                    pq.pop();
                    happy += drugi.first;
                    if(drugi.first == 'a') a--;
                    else if(drugi.first == 'b') b--;
                    else c--;
                    if(drugi.second - 1 > 0) pq.push({drugi.first, drugi.second - 1});
                    pq.push(pom);
                } else {
                    happy += pom.first;
                    if(pom.first == 'a') {
                        a--;
                    } else if(pom.first == 'b') {
                        b--;
                    } else {
                        c--;
                    }
                    if(pom.second - 1 > 0) pq.push({pom.first, pom.second - 1});
                }
            } else {
                happy += pom.first;
                if(pom.first == 'a') {
                    a--;
                } else if(pom.first == 'b') {
                    b--;
                } else {
                    c--;
                }
                if(pom.second - 1 > 0) pq.push({pom.first, pom.second - 1});
            }
        }

        return happy;
        
    }
};