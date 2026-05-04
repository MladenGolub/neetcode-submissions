class MedianFinder {

    vector<int> lista;

public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        lista.push_back(num);
    }
    
    double findMedian() {
        sort(lista.begin(), lista.end());
        int n = lista.size();
        if(n%2) {
            return lista[n/2];
        } else {
            return (lista[n/2] + lista[n/2 - 1]) / 2.0;
        }
    }
};
