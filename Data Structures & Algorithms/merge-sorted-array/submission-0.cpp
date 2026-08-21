class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = m - 1;
        int j = n-1;
        int next = m + n - 1;
        while(i >= 0 && j >= 0) {
            if(nums1[i] >= nums2[j]) {
                nums1[next] = nums1[i];
                next--;
                i--;
            } else {
                nums1[next] = nums2[j];
                next--;
                j--;
            }
        }

        if(i < 0) {
            while(j >= 0) {
                nums1[next] = nums2[j];
                next--;
                j--;
            }
        } else {
            while(i >= 0) {
                nums1[next] = nums1[i];
                next--;
                i--;
            }
        }

    }
};