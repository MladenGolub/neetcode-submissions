class MedianFinder {

    priority_queue<int> low;//max heap
    priority_queue<int, vector<int>, greater<int>> high;//min heap

public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(low.size() == high.size()) {
            high.push(num);
            low.push(high.top());
            high.pop();
        } else {
            low.push(num);
            high.push(low.top());
            low.pop();
        }
    }
    
    double findMedian() {
        if(low.size() == high.size()) {
            return (low.top() + high.top()) / 2.0;
        } else {
            return low.top();
        }
    }
};
