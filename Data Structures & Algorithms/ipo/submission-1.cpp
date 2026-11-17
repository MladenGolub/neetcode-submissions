class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = capital.size();        
        vector<int> index(n);

        for(int i = 0; i < n; i++) index[i] = i;

        sort(index.begin(), index.end(), [&](int a, int b) {
            return capital[a] < capital[b];
        });

        priority_queue<int> maxHeap;

        int i = 0;

        while(k > 0) {

            while(i < n && w >= capital[index[i]]) {
                maxHeap.push(profits[index[i]]);
                i++;
            }

            if(!maxHeap.empty()) {
                w += maxHeap.top();
                maxHeap.pop();
                k--;
            } else {
                return w;
            }

        }

        return w;
    }
};