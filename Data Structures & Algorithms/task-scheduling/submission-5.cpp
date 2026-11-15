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

        queue<pair<int,int>> pomocni;

        int cnt = 0;

        while(!pq.empty() || !pomocni.empty()) {
            cnt++;

            while(!pomocni.empty() && pomocni.front().second <= cnt) {
                pq.push(pomocni.front().first);
                pomocni.pop();
            }

            if(!pq.empty()) {
                int pom = pq.top();
                pq.pop();
                if((pom - 1) > 0) pomocni.push({pom - 1, cnt + n + 1});
            }
        }

        return cnt;

    }
};
