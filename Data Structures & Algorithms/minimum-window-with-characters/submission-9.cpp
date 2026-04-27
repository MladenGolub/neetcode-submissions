class Solution {
public:
    string minWindow(string s, string t) {

        if(s.size() < t.size()) return "";

        map<char, int> mapaT;
        map<char, int> mapaS;

        char c = 'a';
        while(c != ('z' + 1)) {
            mapaT.insert({c, 0});
            mapaS.insert({c, 0});
            c++;
        }

        c = 'A';
        while(c != ('Z' + 1)) {
            mapaT.insert({c, 0});
            mapaS.insert({c, 0});
            c++;
        }
        //sada bi trebalo da imamo 2 mape koje imaju sva mala i velika slova, i da su im postavljeni cnt na 0 za svako slovo

        for(int i = 0; i < t.size(); i++) {
            mapaT[t[i]] += 1;//racunam cnt za sva slova koja se nalaze u t stringu
            //mapaS[s[i]] += 1;//prvi t.size() slova u stringu s povecavam njihov cnt
        }

        int matches = 0;//ja zelim da mi matches bude jednak duzini stringa t, ako je jednak tada znaci da smo nasli jedan prozor u kome se nalaze svi karakteri iz t u s, ali to ne mora da je min
        int minProzor = 1001;
        int minStart = 0;

        // for(int i = 0; i < t.size(); i++) {
        //     if(mapaT[t[i]] != 0 && mapaS[t[i]] >= mapaT[t[i]]) {
        //         matches++;//ako su isti i to slovo postoji u t povecavamo broj pogodaka
        //     }
        // }
        cout << matches << endl;

        int l = 0;
        int r = 0;
        for(; r < s.size();) {
            cout << 2;
            if(matches == t.size()) {//ako smo nasli prozor, proveravamo njegovu duzinu i pamtimo je ako su ispunjeni uslovi
                while(matches == t.size()) {
                    cout << 1;
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
            mapaS[s[r]] += 1;
            if(mapaT[s[r]] !=0 && mapaS[s[r]] <= mapaT[s[r]]) matches++;
            r++;
        }

        while(matches == t.size()) {
            cout << 3;
            int pom = r - l;
            if(pom < minProzor) {
                minProzor = pom;
                minStart = l;
            }
            mapaS[s[l]]--;//skidamo jednog
            if(mapaT[s[l]] != 0 && mapaS[s[l]] < mapaT[s[l]]) matches--;
            l++;
        }
        
        if(minProzor == 1001) return "";
        return s.substr(minStart, minProzor);
    }
};
