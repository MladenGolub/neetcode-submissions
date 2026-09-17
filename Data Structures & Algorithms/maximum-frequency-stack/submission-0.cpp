class FreqStack {

    unordered_map<int, stack<int>> stacks;
    int maxCnt;
    unordered_map<int, int> cnt;

public:
    FreqStack() {
        this->maxCnt = 0;
    }
    
    void push(int val) {
        int valCnt;
        if(this->cnt[val]) {
            valCnt = 1 + this->cnt[val];
        } else {
            valCnt = 1;
        }
        this->cnt[val] += 1;
        if(valCnt > this->maxCnt) {
            this->maxCnt = valCnt;
            this->stacks[valCnt] = stack<int>();
        }
        this->stacks[valCnt].push(val);
    }
    
    int pop() {
        int res = this->stacks[this->maxCnt].top();
        this->stacks[this->maxCnt].pop();
        this->cnt[res] -= 1;
        if(this->stacks[this->maxCnt].empty()) {
            this->maxCnt -= 1;
        }
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */