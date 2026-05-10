#include <map>

class LRUCache {
    //kada pristupimo nekom elementu mape, njemu dajemo najveci broj, a to je kapacitet, a sve one koji su bili veci od njegovog prethodnog broja moramo da
    //umanjimo za 1, da bi znali kome smo najdavnije pristupili
private:
    
    std::map<int, int> mapa;
    int cap;
    int size;
    std::map<int, int> pristup;//mapa u kojoj ce mi kljuc biti vrednost iz prve mape, a vrednost ce biti kada je pristupano tom elementu


public:

    LRUCache(int capacity) {
        this->cap = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        if(mapa.find(key) == mapa.end()) {
            return -1;
        }
        int ret = mapa[key];
        int prethodna = pristup[key];//vrednost koju je prethodno imao nas element
        pristup[key] = cap - 1;
        for (std::map<int,int>::iterator it=pristup.begin(); it!=pristup.end(); ++it) {
            if(it->first != key && it->second >= prethodna) {
                it->second = it->second - 1;
            }
        }

        return mapa[key];
    }
    
    void put(int key, int value) {
        if(mapa.find(key) != mapa.end()) {
            mapa[key] = value;
            int prethodna = pristup[key];
            pristup[key] = cap - 1;
            for (std::map<int,int>::iterator it=pristup.begin(); it!=pristup.end(); ++it) {
                if(it->first != key && it->second >= prethodna) {
                    if(it->second != 0) it->second = it->second - 1;
                }
            }
        } else {
            if(size == cap) {
                int pom;
                for(std::map<int, int>::iterator it = pristup.begin(); it != pristup.end(); ++it) {
                    if(it->second == 0) {
                        pom = it->first;
                    }
                }
                pristup.erase(pom);
                mapa.erase(pom);
                size--;
            }//ako nam je mapa bila puno morali smo da uklonimo el. kome smo najdavnije pristupali
        
            mapa.insert(std::pair<int, int>(key, value));
            size++;
            pristup.insert(std::pair<int, int>(key, cap-1));//dodajemo novi element, sto znaci da smo njemu najskorije pristupili
            for (std::map<int,int>::iterator it=pristup.begin(); it!=pristup.end(); ++it) {
                if(it->first != key) {
                    if(it->second != 0) it->second = it->second - 1;
                }
            }
        }
    }
};
