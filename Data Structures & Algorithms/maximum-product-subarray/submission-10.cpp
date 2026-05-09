class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxP = 1;
        int minP = 1;
        int res = nums[0];

        for(auto num : nums) {
            int tmp = maxP * num;
            maxP = max(max(maxP * num, minP * num), num);//zelim da vidim da li je maksimalno ono sto imam do sada puta trenutni broj, ili ono sto je minimalno do sada puta tr broj jer je moguce
            //da tr broj bude negativan i da preokrene ono sto je maksimalno u minmalno i obrnuto
            minP = min(min(tmp, minP * num), num);
            res = max(res, maxP);
        }

        return res;

    }
};
