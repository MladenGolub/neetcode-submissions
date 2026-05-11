#include <map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ret;

        map<int, int> mapaPonavljanja;

        for(int i = 0; i < nums.size(); i++) {
            if(mapaPonavljanja.find(nums[i]) == mapaPonavljanja.end()) {
                mapaPonavljanja.insert({nums[i], 1});
            } else {
                mapaPonavljanja[nums[i]] = mapaPonavljanja[nums[i]] + 1;
            }
        }        

        for(const auto& i : mapaPonavljanja) {
            cout << "Broj: " << i.first << ", " << "ponavljanja: " << i.second << endl; 
        } 

        int j = 0;
        int max = 0;
        int maxKey = 0;
        while(j < k) {
            for(const auto& it : mapaPonavljanja) {
                if(it.second > max) {
                    max = it.second;
                    maxKey = it.first;
                }
            }
            ret.push_back(maxKey);
            mapaPonavljanja.erase(maxKey);
            max = 0;
            j++;
        }
        return ret;
    }

    
};
