class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<double,int>> pq;

        for(int i = 0; i < points.size(); i++) {
            pq.push({pow(points[i][0], 2) + pow(points[i][1], 2), i});
            if(pq.size() > k) pq.pop();
        }//ubacili smo sve duzine tacaka, zajedno sa mestom na kojem se nalaze u points matrici

        vector<vector<int>> res;

        while(!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }

        return res;

    }
};
