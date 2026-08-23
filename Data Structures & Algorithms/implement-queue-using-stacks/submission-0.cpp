class MyQueue {

    stack<int> stek1;
    stack<int> stek2;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!stek1.empty()) {
            stek2.push(stek1.top());
            stek1.pop();
        }
        stek1.push(x);
        while(!stek2.empty()) {
            stek1.push(stek2.top());
            stek2.pop();
        }
    }
    
    int pop() {
        int ret = stek1.top();
        stek1.pop();
        return ret;
    }
    
    int peek() {
        return stek1.top();
    }
    
    bool empty() {
        return stek1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */