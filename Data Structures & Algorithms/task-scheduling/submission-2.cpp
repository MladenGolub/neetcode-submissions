class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int cnt;
        unordered_map<char,int> freq;

        for(char t : tasks) {
            freq[t]++;
        }

        priority_queue<int> pq;

        for(auto &p : freq) {
            pq.push(p.second);
        }

        queue<pair<int, int>> pomocniRed;//ovde cemo cuvati vrednost koju vracamo u prioritetni red, zajedno sa vrednostu u kom vremenskom trenutku smemo da vratimo 
        //tu velicinu
        cnt = 0;//merac za vreme
        while(!pq.empty() || !pomocniRed.empty()) {
            cnt++;
                
            while (!pomocniRed.empty() && pomocniRed.front().second <= cnt) {
                pq.push(pomocniRed.front().first);
                pomocniRed.pop();
            } 

            if(!pq.empty()) {
                int pom1 = pq.top();//ovo je samo broj koliko ih jos ima
                pq.pop();
                if((pom1 - 1) > 0) pomocniRed.push({pom1-1, cnt+n+1});
            } 
            cout << cnt << endl;
        }

        return cnt;

        //sada znamo koliko ih ima, i sve te brojke smo upisali u pq




    }
};
