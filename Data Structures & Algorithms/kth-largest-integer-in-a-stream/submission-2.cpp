class KthLargest {
private:

    priority_queue<int> nums;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++) {
            this->nums.push(nums[i]);
        }
        this->k = k;
    }
    
    int add(int val) {
        nums.push(val);
        int cnt = k;
        vector<int> pom;
        int p;
        while(cnt != 0) {
            p = this->nums.top();
            this->nums.pop();
            pom.push_back(p);
            cnt--;
        }

        while(pom.size() != 0) {
            this->nums.push(pom.back());
            pom.pop_back();
        }

        return p;

    }
};
