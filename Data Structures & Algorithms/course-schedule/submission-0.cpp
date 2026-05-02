class Solution {

    map<int, vector<int>> mapa;
    set<int> visited;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(int i = 0; i < numCourses; i++) {
            mapa[i] = vector<int>();
        }

        for(auto& p: prerequisites) {
            mapa[p[0]].push_back(p[1]);
        }//za svaki cvor dodajemo koje on ima preduslove za slusanje


        for(int i = 0; i< numCourses; i++) {
            if(!dfs(i)) return false;
        }

        return true;

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
        visited.erase(course);
        mapa[course] = vector<int>();//stavljamo ga na prazan
        return true;
    }
};
