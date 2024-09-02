class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;
        if(low == high){
            if(low & 1) return 1;
            else return 0;
        }
        if((low & 1) && (high & 1)){
            ans = 2 + (high - low - 1) / 2;
        }
        else{
            ans = 1 + (high - low - 1) / 2;
        }
        return ans;
    }
};