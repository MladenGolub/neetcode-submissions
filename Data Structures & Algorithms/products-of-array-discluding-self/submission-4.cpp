class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // int suma = 1;
        // vector<int> ret;

        // for(int i = 0; i < nums.size(); i++) {
        //     suma = 1;
        //     for(int j = 0; j < nums.size(); j++) {
        //         if(i != j) {
        //             suma = suma * nums[j];
        //         }
        //     }
        //     ret.push_back(suma);
        // }

        // return ret;

        vector<int> ret;

        int suma = 1;
        int cntNula = 0;
        int ima = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                suma *= nums[i];
            }
            if(nums[i] == 0) {
                cntNula++;
            }
        }

        if(cntNula == 0) {
            ima = 0;
        } else if(cntNula == 1) {
            ima = 1;
        } else {
            ima = 2;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(ima == 2) {
                ret.push_back(0);
            } else if(ima == 1) {
                if(nums[i] == 0) {
                    ret.push_back(suma);
                } else {
                    ret.push_back(0);
                }
            } else {
                ret.push_back(suma / nums[i]);
            }
        }

        return ret;

    }
};
