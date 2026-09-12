class Solution {

    vector<bool> used;

    bool dfs(int i, int trSuma, int target, vector<int>& nums, int& cnt) {
        if(cnt == 0) return true;
        if(i >= nums.size()) {
            if(trSuma == target) {
                cnt--;
                return true;
            }
            return false;
        }
        if(trSuma > target) return false;
        if(!used[i]) {
            used[i] = true;
            if(dfs(i + 1, trSuma + nums[i], target, nums, cnt)) return true;
            used[i] = false;
            dfs(i + 1, trSuma, target, nums, cnt);
        } else {
            if(dfs(i + 1, trSuma, target, nums, cnt)) return true;
        }
        
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum % k != 0) return false;

        int target = totalSum / k;//ovo je suma koja se trazi, svi podskupovi moraju da imaju ovu sumu

        if(*max_element(nums.begin(), nums.end()) > target) return false;

        int cnt = k;

        sort(nums.rbegin(), nums.rend());
        used.assign(nums.size(), false);

        dfs(0, 0, target, nums, cnt);
        cout << k;
        cout << cnt;
        return cnt == 0;

    }
};