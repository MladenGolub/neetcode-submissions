class Solution {
public:
    int search(vector<int>& nums, int target) {//ideja je da se nadje najmanji elem niza, jer onda znamo gde se desila rotacija, jedan deo niza je levo
    //a drugi deo niza je desno i onda imamo 2 sortirana rastuca niza, na kojima mozemo da primenimo binarnu pretragu
        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {
            
            int mid = (left + right) / 2;

            if(nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        //sada imam postavljen left na najmanjem elementu
        int pivot = left;

        int ret = binarySearch(nums, target, 0, pivot - 1);
        if(ret != -1) {//ima ga u donjem delu niza
            return ret;
        }

        return binarySearch(nums, target, pivot, nums.size() - 1);

    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while(left <= right) {
            int mid = (left + right) / 2;

            if(nums[mid] == target) { 
                return mid; 
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
