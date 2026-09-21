/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        int l = 1, r = n - 2, peak, top = 0;

        while(l <= r) {
            int m = (r + l) / 2;
            int left = mountainArr.get(m - 1);
            int mid = mountainArr.get(m);
            int right = mountainArr.get(m + 1);
            if(left < mid && mid < right) {
                l = m + 1;
            } else if(left > mid && mid > right) {
                r = m - 1;
            } else {
                top = m;
                break;
            }
        }

        if(mountainArr.get(top) == target) return top;

        //sada samo binarna od 0 do top ako tu ne nadjemo od top do kraja samo sto je low u tom slucaju kraj niza a 
        //high je top
        int low = 0;
        int high = top;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int pom = mountainArr.get(mid);
            if(target < pom) {
                high = mid - 1;
            } else if(target > pom) {
                low = mid + 1;
            } else {
                return mid;
            }
        }

        //ako ga nismo nasli u prvom delu niza, idemo na drugi deo

        low = n - 1;
        high = top;

        while(low >= high) {
            int mid = low + (high - low) / 2;
            int pom = mountainArr.get(mid);
            if(target < pom) {
                high = mid + 1;
            } else if(target > pom) {
                low = mid - 1;
            } else {
                return mid;
            }
        }

        return -1;
    
    }
};