class Solution {
public:

    int brojSuma(vector<int>& nums, int target) {
        int trSum = 0;
        int cnt = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(trSum + nums[i] > target) {
                cnt++;
                trSum = nums[i];
            } else {
                trSum += nums[i];
            }
        }

        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
        
        int minSum = 0;
        int maxSum = 0;

        for(int num : nums) {
            if(minSum < num) minSum = num;
            maxSum += num;
        }

        int ret = maxSum;

        while(minSum <= maxSum) {
            int mid = minSum + (maxSum - minSum) / 2;

            int cntSum = brojSuma(nums, mid);

            if(cntSum > k) {
                minSum = mid + 1;
            } else {
                maxSum = mid - 1;
                if(ret > mid) ret = mid;
            }
        }

        return ret;
    
    }
};