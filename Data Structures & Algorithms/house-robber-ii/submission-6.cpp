class Solution {

private:

int robber(vector<int>& nums) {
        int levi = 0;
        int desni = 0;
    
        for(int i = 0; i<nums.size(); i++) {
            int curr = max(levi + nums[i], desni);
            levi = desni;
            desni = curr;
        }

        return desni;
    }

public:
    int rob(vector<int>& nums) {

        if(nums.size()==1) return nums[0];
        
        int prvi = 0;
        int poslednji = 0;

        vector<int> v1(nums.begin(), nums.end() - 1);

        prvi = robber(v1);

        vector<int> v2(nums.begin()+1, nums.end());

        poslednji = robber(v2);

        return (prvi >= poslednji)? prvi : poslednji;

    }
};



//ako je neparan broj kuca onda mogu da dodjem do poslednje ako krenem od prve,
//ako je paran broj kuca svakako ne mogu da opljackam i prvu i poslednju
