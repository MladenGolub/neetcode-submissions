class StockSpanner {

    vector<int> stek;

public:
    StockSpanner() {
        stek = vector<int>();
    }
    
    int next(int price) {
        int ret = 1;

        for(int i = stek.size() - 1; i >= 0; i--) {
            if(stek[i] <= price) ret++;
            else break;
        }
        stek.push_back(price);

        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */