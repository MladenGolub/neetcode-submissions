class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> mapaPonavljanja;

        auto cmp = [](const pair<int, int> a, const pair<int, int> b) {
            return a.second < b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for(int i = 0; i < nums.size(); i++) {
            if(mapaPonavljanja.find(nums[i]) == mapaPonavljanja.end()) {
                mapaPonavljanja[nums[i]] = 1;
            } else {
                mapaPonavljanja[nums[i]]++;
            }
        }

        for(auto it = mapaPonavljanja.begin(); it != mapaPonavljanja.end(); ++it) {
            pq.push({it->first, it->second});
        }

        int j = 0;
        vector<int> ret;
        while(j < k) {
            ret.push_back(pq.top().first);
            pq.pop();
            j++;
        }

        return ret;

    }
};
