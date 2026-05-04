class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;

        for(int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }//ubacimo sve 

        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int pom;
            if(x == y) {
                pom = 0;
            } else {
                pom = abs(x - y);//svejedno mi je ko je veci, uzimam apsolutnu razliku
            }
            if(pom != 0) {
                pq.push(pom);//ako je 0 nema potrebe da ga vracam, jer su se oba kamena unistila
            }
        }

        return pq.empty() ? 0 : pq.top();

    }
};
