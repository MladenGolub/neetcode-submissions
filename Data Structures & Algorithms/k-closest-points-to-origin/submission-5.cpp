class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        auto cmp = [](const vector<int> a, const vector<int> b) {
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> max_heap;

        for(int i = 0; i < points.size(); i++) {

            max_heap.push(points[i]);
            if(max_heap.size() > k) {
                max_heap.pop();
            }
        }

        vector<vector<int>> res;
        while (!max_heap.empty()) {
            res.push_back(max_heap.top());
            max_heap.pop();
        }
        return res;

    }
};
