class Solution {
public:
    // int solveRE(vector<int>& cost, int index){
    //     if(index >= cost.size()){
    //         return 0;
    //     }
    //     return (cost[index] + min(solveRE(cost, index + 1), solveRE(cost, index + 2)));
    // }
    int solveMem(vector<int>& cost, int index, vector<int> &dp){
        if(index >= cost.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        return dp[index] = (cost[index] + min(solveMem(cost, index + 1, dp), solveMem(cost, index + 2, dp)));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(solveMem(cost, 0, dp), solveMem(cost, 1, dp));
    }
};