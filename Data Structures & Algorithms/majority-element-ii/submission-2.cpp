class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        //nadjem 2 najcesca broja i ako obojica imaju preko n/3 pojavljivanja, to znaci da nema treceg takvog, a ako nijedan od najcescih el nema preko n/3 onda je prazan skup ret vrednost

        int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;

        for(int num : nums) {
            if(num == num1) {
                cnt1++;
            } else if(num == num2) {
                cnt2++;
            } else if(cnt1 == 0) {
                num1 = num;
                cnt1 = 1;
            } else if(cnt2 == 0) {
                num2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for(int num : nums) {
            if(num1 == num) {
                cnt1++;
            } else if(num == num2) {
                cnt2++;
            }
        }

        vector<int> ret;
        if(cnt1 > nums.size() / 3) {
            ret.push_back(num1);
        }
        if(cnt2 > nums.size() / 3) {
            ret.push_back(num2);
        }

        return ret;

    }
};