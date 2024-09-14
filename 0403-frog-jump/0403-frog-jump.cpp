class Solution {
public:
    bool solveRE(int index, int prevStep, vector<int>& stones, unordered_map<int, int> &mp){
        int n = stones.size();
        if(index == n - 1){
            //reached the last index
            return true;
        }
        bool ans = false;
        for(int i = prevStep - 1 ; i <= prevStep + 1 ; i++){
            if(i > 0){
                int nextElement = stones[index] + i;
                if(mp.find(nextElement) != mp.end()){
                    ans = ans || solveRE(mp[nextElement], i, stones, mp);
                }
            }
        }
        return ans;
    }
    bool solveMEM(int index, int prevStep, vector<int>& stones, unordered_map<int, int> &mp, vector<vector<int> > &dp){
        int n = stones.size();
        if(index == n - 1){
            //reached the last index
            return true;
        }
        if(dp[index][prevStep] != -1){
            return dp[index][prevStep];
        }
        bool ans = false;
        for(int i = prevStep - 1 ; i <= prevStep + 1 ; i++){
            if(i > 0){
                int nextElement = stones[index] + i;
                if(mp.find(nextElement) != mp.end()){
                    ans = ans || solveMEM(mp[nextElement], i, stones, mp, dp);
                }
            }
        }
        return dp[index][prevStep] = ans;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, int> mp;
        for(int i = 0 ; i < stones.size() ; i++) {
            mp[stones[i]] = i;
        }
        if(stones[1] != 1) return false;
        vector<vector<int> > dp(n, vector<int>(2001, -1));
        return solveMEM(0, 0, stones, mp, dp);
    }
};