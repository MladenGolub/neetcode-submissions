class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.size();
        int cnt[26] = {0};

        for (char c : s) cnt[c - 'a']++;

        for (int i = 0; i < 26; i++)
            if (cnt[i] > (n + 1) / 2) return "";

        // max-hip: {preostali broj, karakter}
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++)
            if (cnt[i] > 0) pq.push({cnt[i], 'a' + i});

        string ret = "";

        while (!pq.empty()) {
            auto prvi = pq.top(); pq.pop();

            if (!ret.empty() && ret.back() == prvi.second) {
                // ne smemo isti karakter, uzimamo drugi po redu
                if (pq.empty()) return "";
                auto drugi = pq.top(); pq.pop();

                ret.push_back(drugi.second);
                if (--drugi.first > 0) pq.push(drugi);

                pq.push(prvi); // prvi vraćamo nepromenjen
            } else {
                ret.push_back(prvi.second);
                if (--prvi.first > 0) pq.push(prvi);
            }
        }

        return ret;

    }
};