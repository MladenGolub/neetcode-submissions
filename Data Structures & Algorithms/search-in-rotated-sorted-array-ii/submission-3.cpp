class Solution {
public:
    bool binarySearch(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        // pivot = prvi element druge sortirane polovine (0 ako je niz ceo sortiran)
        int pivot = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == 0) return binarySearch(nums, 0, n - 1, target);

        return binarySearch(nums, 0, pivot - 1, target) ||
               binarySearch(nums, pivot, n - 1, target);
    }
};