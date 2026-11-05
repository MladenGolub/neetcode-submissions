class Solution {
public:
    //PREVISE KOMPLIKOVANO VREMENSKO RESENJE
    // vector<int> twoSum(vector<int>& nums, int target) {
        
    //     vector<int> povratna;

    //     for(int i = 0; i < nums.size() - 1; i++) {
    //         for(int j = i+1; j < nums.size(); j++) {
    //             if(nums[i] + nums[j] == target) {
    //                 povratna = {i, j};
    //             }
    //         }
    //     }

    //     return povratna;

    // }

    vector<int> twoSum(vector<int>& nums, int target) {

        map<int, int> vrednostiIndeksi;

        for(int i = 0; i < nums.size(); i++) {
            if(vrednostiIndeksi.find(target - nums[i]) != vrednostiIndeksi.end()) {
                return {vrednostiIndeksi[target - nums[i]], i};
            } 
            vrednostiIndeksi.insert(pair{nums[i], i});
        }

        return {};

    }
};
