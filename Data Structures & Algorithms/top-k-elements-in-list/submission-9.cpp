class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mapaPonavljanja;

        auto cmp = [](const pair<int, int> a, const pair<int, int> b) {
            return a.second > b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for(int i = 0; i < nums.size(); i++) {
            mapaPonavljanja[nums[i]]++;
        }

        for(auto it = mapaPonavljanja.begin(); it != mapaPonavljanja.end(); ++it) {
            pq.push({it->first, it->second});
            if(pq.size() > k) pq.pop();
        }

        vector<int> ret;
        while(!pq.empty()) {
            ret.push_back(pq.top().first);
            pq.pop();
        }

        return ret;

    }
};
