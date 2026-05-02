class Solution {

    set<int> visited;
    map<int, vector<int>> mapa;
    vector<int> redosled;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses; i++) {
            mapa[i] = vector<int>();
        }

        for(auto& p: prerequisites) {
            mapa[p[0]].push_back(p[1]);
        }//za svaki cvor dodajemo koje on ima preduslove za slusanje

        for(int i = 0; i < numCourses; i++) {
            if(mapa[i].size() == 0) redosled.push_back(i);
        }

        for(int i = 0; i< numCourses; i++) {
            if(!dfs(i)) return vector<int>();
        }
        vector<int> res;
        for(auto& r: redosled) {
            res.push_back(r);
        }

        return res;

    }

    bool dfs(int course) {
        if(visited.find(course) != visited.end()) return false;
        if(mapa[course].size() == 0) {
            return true;
        }

        visited.insert(course);
        for(auto& p: mapa[course]) {
            if(!dfs(p)) return false;
        }
        visited.erase(course);//mi prvo ubacimo svaki koji trenutno obilazimo, jer moze doci do petlje ako je njih vise povezano u oba smera, zato pazimo koje smo obisli,
        //kada zavrsimo taj dfs obilazak onda moramo da izbacimo sve te cvorove koje smo obilazili jer se oni ne nalaze mozda na drugoj putanji na koju sada krecemo
        mapa[course] = vector<int>();//stavljamo ga na prazan
        redosled.push_back(course);
        return true;
    }
};
