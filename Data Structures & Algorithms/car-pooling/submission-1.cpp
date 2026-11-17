class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int n = trips.size();
        vector<int> index(n);

        for(int i = 0; i < n; i++) index[i] = i;

        sort(index.begin(), index.end(), [&](int a, int b) {
            return trips[a][1] < trips[b][1];
        });

        int curSize = 0;

        //zelim da u pq cuvam putovanje, kada treba da se zavrsi put, i koliko ljudi putuje i zelim da mi bude min_heap preko toga kada se zavrsava put, tj da na vrhu bude onaj koji prvi nailazi
        //{to, peopleNum}

        auto cmp = [](pair<int,int> a, pair<int, int> b) {
            return a.first > b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_heap(cmp);

        int i = 0;//ja idem redom kroz niz index, njih tu ima n ne zanima me kojim redosledom iz trips ih uzimam jer mi je redosled odredjen sortiranjem u nizu index
        int km = 0;

        while(i < n) {

            km = trips[index[i]][1];

            if(min_heap.empty() && km <= trips[index[i]][1]) {
                if(curSize + trips[index[i]][0] <= capacity) {
                    curSize+= trips[index[i]][0];
                    min_heap.push({trips[index[i]][2], trips[index[i]][0]});
                    i++;
                } else return false;
            } else {
                while(!min_heap.empty() && min_heap.top().first <= km) {
                    curSize -= min_heap.top().second;
                    min_heap.pop();
                } 

                if(curSize + trips[index[i]][0] <= capacity) {
                    curSize += trips[index[i]][0];
                    min_heap.push({trips[index[i]][2], trips[index[i]][0]});
                    i++;
                } else {
                    return false;
                } 
            } 
        }

        return true;

    }
};