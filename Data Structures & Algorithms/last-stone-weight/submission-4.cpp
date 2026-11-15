class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> max_heap;

        for(int stone : stones) {
            max_heap.push(stone);
        }

        while(max_heap.size() > 1) {
            int x = max_heap.top();
            max_heap.pop();
            int y = max_heap.top();
            max_heap.pop();

            if(x < y) {
                y = y - x;
                max_heap.push(y);
            } else if(x > y) {
                x = x - y;
                max_heap.push(x);
            }
        }

        if(max_heap.size() == 1) {
            return max_heap.top();
        } else {
            return 0;
        }

    }
};
