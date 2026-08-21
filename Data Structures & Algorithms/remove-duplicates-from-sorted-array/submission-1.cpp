class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 1;
        int j = 0;
        int k = 1;
        int currIndx = 0;
        int curr = nums[0];
        while(i < nums.size()) {
            if(nums[i] == curr) {
                i++;
            } else {
                k++;
                currIndx++;
                curr = nums[i];
                i++;
                nums[currIndx] = curr;
            }
        }
        
        return k;

    }
};