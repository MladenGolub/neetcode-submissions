class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // for(int i = 0; i < matrix.size(); i++) {
        //     int left = 0; int right = matrix[i].size() - 1; 
        //     while(left <= right) {
        //         int mid = left + (right - left) / 2;
        //         if(matrix[i][mid] == target) {
        //             return true;
        //         }
        //         if(matrix[i][right] < target) break;//ako je najdesniji manji od target onda idemo u sl red matrice 
        //         if(matrix[i][mid] < target) {
        //             left = mid + 1;
        //         }
        //         if(matrix[i][mid] > target) {
        //             right = mid - 1;
        //         }
        //     }
        // }
        // return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / n;
            int col = mid % n;
            int val = matrix[row][col];

            if(val == target) {
                return true;
            }
            if(val < target) {
                left = mid + 1;
            }
            if(val > target) {
                right = mid - 1;
            }
        }
        return false;
    }
};
