class Twitter {
private:

    map<int, set<int>> mapaPracenja;//u njoj mogu da pratim ko koga prati 
    priority_queue<pair<int, pair<int, int>>> tvitovi;

    inline static int id = 0;
    
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        int tId = id++;
        tvitovi.push({tId, {tweetId, userId}});//ubacujemo ko je tvitovao i koji je broj tvita
    }
    
    vector<int> getNewsFeed(int userId) {
        int cnt = 10;
        vector<pair<int, pair<int, int>>> pom;
        vector<int> res;
        while(!tvitovi.empty()) {
            if(cnt == 0) break;
            pair<int, pair<int, int>> pom1 = tvitovi.top();
            pair<int, int> pom2 = pom1.second;
            pom.push_back(pom1);
            tvitovi.pop();

            if(userId == pom2.second) {
                res.push_back(pom2.first);//guramo tvitId
                cnt--;
            } else if(mapaPracenja[userId].find(pom2.second) != mapaPracenja[userId].end()) {
                res.push_back(pom2.first);
                cnt--;
            }
        }

        for(int i = 0; i < pom.size(); i++) {
            tvitovi.push(pom[i]);
        }

        return res;
        
    }
    
    void follow(int followerId, int followeeId) {
        mapaPracenja[followerId].insert(followeeId);//samo ubacimo u set, a set koristimo da ne bi doslo do slucaja da isti covek hoce nekoga 2 puta da zaprati
    }
    
    void unfollow(int followerId, int followeeId) {
        mapaPracenja[followerId].erase(followeeId);//samo ga izbacimo iz seta
    }
};
