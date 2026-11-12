class Solution {
public:

    int maxElemInMap(map<char, int> mapa) {
        int ret = 0;
        for(std::pair<char, int> el : mapa) {
            
            if(ret < el.second) {
                ret = el.second;
            }
        }
        return ret;
    }

    int characterReplacement(string s, int k) {
        
        int res = 0;
        int pomRes = 0;
        int l = 0;
        int maxF = 0;
        bool ls = false;

        map<char, int> count;

        for(int r = 0; r < s.size();) {//kako prolazim kroz string moram da dodajem, ako ne postoje karakteri u mapi, ako postoje samo cnt povecavam
            if(count.find(s[r]) == count.end()) {//ako ne postoji u mapi dodajemo karakter u mapu
                count.insert(std::pair<char, int>(s[r], 1));
            } else {
                if(ls == true) {
                    ls = false;
                } else {
                    count[s[r]] = count[s[r]] + 1;
                }
            }//sada moram da proverim da li nam uslov i dalje valja

            
            maxF = maxElemInMap(count);
            //cout << maxF;

            //ako je validan prozor i dalje samo ga sirimo
            if((r - l + 1) - maxF <= k) {
                r = r + 1;
                pomRes += 1;
            } else {//ako menjam prozor, moram da promenim cnt koji se nalazi za taj kljuc u mapi
                count[s[l]] = count[s[l]] - 1;
                l = l + 1;
                ls = true;
                if(pomRes > res) { res = pomRes; }
                pomRes = pomRes - 1;
            }

        } 

        if(res < pomRes) { res = pomRes; }

        return res;

    }
};
