class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        vector<int> ret;
        int n = tasks.size();
        vector<int> indx(n);

        for(int i = 0; i < n; i++) indx[i] = i;

        sort(indx.begin(), indx.end(), [&](int a, int b) {
            return tasks[a][0] < tasks[b][0];
        });//sortiramo indekse svih taskova tako da znamo koji dolazi prvi, tako da nam je sada 0-ti el u nizu indx prvi task koji stize da moze da se izvrsava

        //cuvamo u redu {trajanje, index}, posto smo stavili greater on ce nam uraditi tacno ono sto nam treba poredice nove el koji nailaze i ako je trajanje a vece od trajanje b vratice true
        //a to mi zelimo jer ce onda b sa manjim trajanjem da ide na vrh, a ako je isto onda ce pitati da li je veci index, a ako je a index veci desice se isto b sa manjim indeksom ide na vrh
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        long long time = 0;
        int i = 0;

        while(ret.size() < n) {
            if(min_heap.empty() && time < tasks[indx[i]][0]) {
                time = tasks[indx[i]][0];//ako nema nikoga da izvrsava guramo vreme na vreme prvog koji je spreman da se izvrsava
            }

            while(i < n && tasks[indx[i]][0] <= time) {
                min_heap.push({tasks[indx[i]][1], indx[i]});
                i++;
            }

            pair<int, int> pom = min_heap.top();
            min_heap.pop();
            ret.push_back(pom.second);
            time += pom.first;
        }

        return ret;

    }
};