class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char, int> freq;

        for(char t : tasks) {
            freq[t]++;
        }

        priority_queue<int> pq;

        for(auto& f : freq) {
            pq.push(f.second);
        }

        int cnt = 0;

        queue<pair<int, int>> pomocniRed;

        while(!pq.empty() || !pomocniRed.empty()) {
            cnt++;

            if(!pomocniRed.empty() && pomocniRed.front().second <= cnt) {
                pq.push(pomocniRed.front().first);
                pomocniRed.pop();
            }

            if(!pq.empty()) {
                int pom1 = pq.top();
                pq.pop();
                if((pom1 - 1) > 0) pomocniRed.push({pom1 - 1, cnt + n + 1});
            }
        }

        return cnt;
        

    }
};
