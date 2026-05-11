class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int suma;
        vector<int> ret;
        int i = 0;
        int j = numbers.size()-1;
        while(i < j) {
            suma = numbers[i] + numbers[j];
            if(suma > target) {
                j--;
            } else if(suma < target) {
                i++;
            } else {
                ret.push_back(i+1);
                ret.push_back(j+1);
                return ret;
            }
        }
        return {};
    }
};
