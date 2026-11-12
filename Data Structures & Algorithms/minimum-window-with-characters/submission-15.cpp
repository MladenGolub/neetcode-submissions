class Solution {
public:
    string minWindow(string s, string t) {

        if(s.size() < t.size()) return "";

        int mapaT[128] = {0};
        int mapaS[128] = {0};

        //sada bi trebalo da imamo 2 mape koje imaju sva mala i velika slova, i da su im postavljeni cnt na 0 za svako slovo

        for(int i = 0; i < t.size(); i++) {
            mapaT[t[i]] += 1;//racunam cnt za sva slova koja se nalaze u t stringu
        }

        int matches = 0;//ja zelim da mi matches bude jednak duzini stringa t, ako je jednak tada znaci da smo nasli jedan prozor u kome se nalaze svi karakteri iz t u s, ali to ne mora da je min
        int minProzor = 100001;
        int minStart = 0;

        int l = 0;
        int r = 0;
        for(; r < s.size();) {
            mapaS[s[r]] += 1;
            if(mapaT[s[r]] !=0 && mapaS[s[r]] <= mapaT[s[r]]) matches++;
            r++;
            if(matches == t.size()) {//ako smo nasli prozor, proveravamo njegovu duzinu i pamtimo je ako su ispunjeni uslovi
                while(matches == t.size()) {
                    int pom = r - l;
                    if(pom < minProzor) {
                        minProzor = pom;
                        minStart = l;
                    }
                    mapaS[s[l]] -= 1;//skidamo jednog
                    if(mapaT[s[l]] != 0 && mapaS[s[l]] < mapaT[s[l]]) matches--;
                    l++;
                }
            }
            
        }
        
        if(minProzor == 100001) return "";//ako ne postoji prozor koji zadovoljava uslov
        
        return s.substr(minStart, minProzor);
    }
};
