class Solution {

    int dfs(vector<int>& nums, int i, int total){
        if(i == nums.size()) {
            return total;
        }
        return dfs(nums, i+1, total ^ nums[i]) + dfs(nums, i+1, total);//prosledjujem dalje oba slucaja i da sam uzeo trenutni el i da sam ga preskocio
    }

public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
};