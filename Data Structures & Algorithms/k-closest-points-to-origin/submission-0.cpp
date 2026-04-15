class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        map<double, int> mapa;//u mapu cu ubacivati distancu od koordinatnog pocetka i indeks na kome se nalazi tacka u matrici points
        priority_queue<pair<double,int>> pq;
        for(int i = 0; i < points.size(); i++) {
            //mapa.insert({sqrt(pow(points[i][0],2) + pow(points[i][1],2)), i});
            pq.push({sqrt(pow(points[i][0],2) + pow(points[i][1],2)), i});//ubacujemo distance od koordinatnog pocetka u red sa prioritetom

            if(pq.size() > k) {
                pq.pop();
            }
        }//imamo sada mapu koja se sama uredila i cuva udaljenost od koordinatnog pocetka i index u matrici na kojem se nalazi
        // for(auto it: mapa) {
        //     cout << it.first << " " << it.second << endl;
        // }
        vector<vector<int>> result;
        // int i = 0;
        // for(auto it = mapa.begin(); it != mapa.end() && i < k; it++) {
        //     vector<int> curr;
        //     curr.push_back(points[it->second][0]);
        //     curr.push_back(points[it->second][1]);
        //     result.push_back(curr);
        //     i++;
        // }


        for(int i = 0; i < k; i++) {
            result.push_back({points[pq.top().second][0], points[pq.top().second][1]});
            pq.pop();
        }

        return result;
       
    }
};
