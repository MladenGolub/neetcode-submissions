class Solution {

    unordered_map<string, int> dp;

public:
    int maxProfit(vector<int>& prices) {
    
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));

        for(int i = prices.size()-1; i >= 0; i--) {
            for(int j = 1; j >= 0; j--) {
                if(j == 1) {//ako je j == 1 to znaci da smo u fazi kupovine, kupovina nam je durga kolona tj [][1], a prodaja nam je [][0]
                    int buy = dp[i+1][0] - prices[i];//iduci u dp koji je u sell fazi minus ona vr koju smo prodali
                    int cool = dp[i+1][1];//ako samo radimo cooldown onda uzimamo sledecu buy vrednost ne menjamo operaciju u sel
                    dp[i][1] = max(buy, cool);
                } else {
                    int sell = (i + 2 < prices.size()) ? dp[i+2][1] + prices[i] : prices[i];
                    int cool = dp[i+1][0];
                    dp[i][0] = max(sell, cool);
                }
            }
        }

        return dp[0][1];

    }
};
