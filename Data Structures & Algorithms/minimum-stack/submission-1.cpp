class MinStack {
private:

    vector<int> stek;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        stek.push_back(val);//ubacujemo kao poslednji el niza
    }
    
    void pop() {
       if(!stek.empty()) {
            stek.pop_back();
        }
        return;
    }
    
    int top() {
        if(!stek.empty()) {
            return stek.back();
        }
        return -1;
    }
    
    int getMin() {
        if(!stek.empty()) {
            int min = stek[0];
            for(int i = 1; i < stek.size(); i++) {
                if(stek[i] < min) {
                    min = stek[i];
                }
            }
            return min;
        } else {
            return -1;
        }
    }
};
