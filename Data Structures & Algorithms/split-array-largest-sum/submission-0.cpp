class Solution {
public:

    int countSums(vector<int>& nums, int target) {
        int cnt = 1;

        int trSuma = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(trSuma + nums[i] <= target) {
                trSuma += nums[i];
            } else {
                cnt++;
                trSuma = nums[i];
            }
        }
        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
        
        int max = nums[0];
        int maxSum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > max) {
                max = nums[i];
            }
            maxSum += nums[i];
        }        

        int minSum = max;
        
        int mid = 0;
        while(minSum < maxSum) {
            mid = minSum + (maxSum - minSum) / 2;
            int cnt = countSums(nums, mid);

            if(cnt > k) {
                minSum = mid + 1;
            } else {
                maxSum = mid;
            }
        }

        return minSum;

    }
};