class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        cost.push_back(0);

        int jedan = 0;
        int dva = 0;

        //moram da ga postavim na size - 2 jer sam dodao jednu nulu na kraj niza, da mi bude lakse
        for(int i = cost.size()-2; i >= 0; i--) {
            if(i == cost.size()-2){//ako sam na poslednjem elementu ne menjam mu vrednost ona je samo ono sto je bila, jer je cena svakako ta koja tu pise, nema razlike da li skacem 1 ili 2 stigao sam do vrha
                continue;
            } else {
                jedan = cost[i] + cost[i+1];
                dva = cost[i] + cost[i+2];
                cost[i] = (jedan >= dva)? dva : jedan;
            }
        }

        return (cost[0] > cost[1])? cost[1] : cost[0];

    }
};
