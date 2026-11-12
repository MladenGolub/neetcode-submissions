class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int ind;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] >= x) {
                ind = i;
                break;
            }
        }//ovde sam uzeo index broja x ili prvog veceg od njega!

        int l, r;
        if(arr[ind] == x) {
            l = ind;
            r = ind;
        } else {
            if(ind - 1 >= 0) {
                if(abs(arr[ind-1] - x) < abs(arr[ind] - x) || 
                ((abs(arr[ind-1] - x) == abs(arr[ind] - x)) && arr[ind-1] < arr[ind])) {
                    l = ind-1;
                    r = ind-1;
                } else {
                    l = ind;
                    r = ind;
                }
            } else {
                l = ind;
                r = ind;
            }
        }
        cout << l;
        //sada je dobar pocetni index, sada samo treba da idemo oko njega da uzimamo brojeve

        int cnt = k - 1;

        while(cnt > 0) {
            if(l - 1 >= 0 && r + 1 < arr.size()) {
                if(abs(arr[l-1] - x) < abs(arr[r+1] - x) || 
                ((abs(arr[l-1] - x) == abs(arr[r+1] - x)) && arr[l-1] < arr[r+1])) {
                    l--;
                    cnt--;
                } else {
                    r++;
                    cnt--;
                }
            } else if(l - 1 >= 0) {
                l = l - 1;
                cnt--;
            } else {//samo uzimamo desni clan
                r = r + 1;
                cnt--;
            }
        }   
        vector<int> ret;
        for(int i = l, j = 0; j < k; i++, j++) {
            ret.push_back(arr[i]);
        }

        return ret;

    }
};