class Solution {

    int brojDana(vector<int>& weights, int maxWeight) {
        int cnt = 1;

        int trSum = 0;
        for(int i = 0; i < weights.size(); i++) {
            if(trSum + weights[i] > maxWeight) {
                cnt++;
                trSum = weights[i];        
            } else {
                trSum += weights[i];
            }
        }
        return cnt;
    
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
    
        int l = 0;
        int r = 0;
        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] > l) {
                l = weights[i];
            }
            r += weights[i];
        }

        while(l < r) {
            int m = (r + l) / 2;

            int ret = brojDana(weights, m);
            if(ret > days) {
                //ako izracunam da mi treba vise dana nego sto su mi oni dali
                //to znaci da mi je suma koju sam prosledio premala
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l;

        //ako imamo 1 dan da prevezemo sve kilaze, minimalni kapacitet broda ce biti suma svih kilaza
        //ako imamo onoliko dana koliko imamo kilaza, to ce nam biti minimalni slucaj, i brod mora imati kilazu
        //jednaku najvecoj kilazi u nizu
        //sada nam je potrebno da redom prolazimo kroz niz i da proveravamo da li mozemo da ga podelimo na onoliko
        //razlicitih suma koliko su nam dali dana, da prevezemo sve kilaze, i kada nadjemo taj slucaj
        //dobicemo i kilazu koja je minimalna za takav prenos

    }
};