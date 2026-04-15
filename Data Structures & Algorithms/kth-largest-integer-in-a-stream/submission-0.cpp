class KthLargest {
private:
    int k;
    vector<int> nums;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i = 0; i < nums.size(); i++) {
            this->nums.push_back(nums[i]);
        }
        sort(this->nums.begin(), this->nums.end());
    }//napravili smo objekat klase
    
    int add(int val) {
        this->nums.push_back(val);
        sort(nums.begin(), nums.end());
        int i = k - 1;
        int j = this->nums.size() - 1;
        while(i > 0 && j > 0) {
            i--;
            j--;
        }
        return this->nums[j];
    }
};
