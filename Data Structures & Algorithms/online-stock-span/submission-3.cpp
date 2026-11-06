class StockSpanner {

    stack<pair<int, int>> stek;

public:
    StockSpanner() {
        stek = stack<pair<int,int>>();
    }
    
    int next(int price) {
        int span = 1;
        while(!stek.empty() && price >= stek.top().first) {
            span = stek.top().second + span;
            stek.pop();
        }

        stek.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */