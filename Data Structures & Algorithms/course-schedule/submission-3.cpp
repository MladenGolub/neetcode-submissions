class Solution {

    map<int, vector<int>> mapa;
    vector<bool> visited;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
        visited.resize(numCourses, false);

        for(auto& p: prerequisites) {
            mapa[p[0]].push_back(p[1]);
        }//za svaki cvor dodajemo koje on ima preduslove za slusanje


        for(int i = 0; i< numCourses; i++) {
            if(!dfs(i)) return false;
        }

        return true;

    }

    bool dfs(int course) {
        if(visited[course]) return false;
        if(mapa[course].size() == 0) {
            return true;
        }

        visited[course] = true;
        for(auto& p: mapa[course]) {
            if(!dfs(p)) return false;
        }
        visited[course] = false;//mi prvo ubacimo svaki koji trenutno obilazimo, jer moze doci do petlje ako je njih vise povezano u oba smera, zato pazimo koje smo obisli,
        //kada zavrsimo taj dfs obilazak onda moramo da izbacimo sve te cvorove koje smo obilazili jer se oni ne nalaze mozda na drugoj putanji na koju sada krecemo
        mapa[course] = vector<int>();//stavljamo ga na prazan
        return true;
    }
};
