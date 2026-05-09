class Solution {

    vector<int> visited;
    map<int, vector<int>> mapa;
    vector<int> redosled;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        visited.resize(numCourses, 0);

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

        return redosled;

    }

    bool dfs(int course) {
        if(visited[course] == 1) return false;//!!!!! NAJBITNIJE U OVOM ZADATKU JE PRACENJE DA LI SE NALAZIMO U PETLJI ZA ODREDJENU POLAZNU TACKU, JER PREKO TOGA ZNAMO DA LI MOZEMO
        //DA SKLONIMO USLOVLJENOST, TJ DA JE ISPUNIMO
        if(visited[course] == 2) return true;
        if(mapa[course].size() == 0) {
            return true;
        }

        visited[course] = 1;
        for(auto& p: mapa[course]) {
            if(!dfs(p)) return false;
        }
        visited[course] = 2;//mi prvo ubacimo svaki koji trenutno obilazimo, jer moze doci do petlje ako je njih vise povezano u oba smera, zato pazimo koje smo obisli,
        //kada zavrsimo taj dfs obilazak onda moramo da izbacimo sve te cvorove koje smo obilazili jer se oni ne nalaze mozda na drugoj putanji na koju sada krecemo
        mapa[course] = vector<int>();//stavljamo ga na prazan
        redosled.push_back(course);
        return true;
    }
};
