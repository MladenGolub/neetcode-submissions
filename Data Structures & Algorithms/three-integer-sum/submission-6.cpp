#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> pomRes;
        vector<vector<int>> result;

        if(nums.size() < 3) return result;

        int i = 0;
        int j = 1;
        int k = 2;

        while(i != nums.size() && j != nums.size() && k != nums.size()) {
            if(nums[i] + nums[j] + nums[k] == 0) {
                vector<int> pom;
                pom.push_back(nums[i]);
                pom.push_back(nums[j]);
                pom.push_back(nums[k]);
                sort(pom.begin(), pom.end());
                pomRes.insert(pom);
                k++;
                if(k == nums.size()) {
                    j++;    
                    k = j + 1;
                    if(j == nums.size()-1) {
                        i++;
                        j = i + 1;
                        k = j + 1;
                    }
                }
            } else {
                k++;
                if(k == nums.size()) {
                    j++;    
                    k = j + 1;
                    if(j == nums.size()-1) {
                        i++;
                        j = i + 1;
                        k = j + 1;
                    }
                }
            }
        }

        for(auto &n : pomRes) {
            result.push_back(n);
        }

        return result;
    }
};
