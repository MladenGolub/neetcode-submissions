class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();
 
        if(m > n) return findMedianSortedArrays(nums2, nums1);

        int l = 0;
        int r = m;
        int total = m + n;
        int half = (total + 1) / 2;

        while(l <= r) {
            int i = l + (r - l) / 2;
            int j = half - i;
        
            int aLeft = (i > 0) ? nums1[i - 1] : INT_MIN;
            int aRight = (i < m) ? nums1[i] : INT_MAX;
            int bLeft = (j > 0) ? nums2[j - 1] : INT_MIN;
            int bRight = (j < n) ? nums2[j] : INT_MAX;
        
            if(aLeft <= bRight && bLeft <= aRight) {
                if(total % 2) {
                    //ako je neparan broj el u oba niza ukupno, onda vracamo min od 2 desna
                    return max(aLeft, bLeft);
                } else {
                    return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0; 
                }
            } else if(aLeft > bRight) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }

        return -1;

    }
};
