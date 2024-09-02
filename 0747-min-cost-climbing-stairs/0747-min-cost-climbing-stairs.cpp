class Solution {
public:
    // int solveRE(vector<int>& cost, int index){
    //     if(index >= cost.size()){
    //         return 0;
    //     }
    //     return (cost[index] + min(solveRE(cost, index + 1), solveRE(cost, index + 2)));
    // }
    // int solveMem(vector<int>& cost, int index, vector<int> &dp){
    //     if(index >= cost.size()){
    //         return 0;
    //     }
    //     if(dp[index] != -1){
    //         return dp[index];
    //     }
    //     return dp[index] = (cost[index] + min(solveMem(cost, index + 1, dp), solveMem(cost, index + 2, dp)));
    // }
    // int solveMem(vector<int>& cost, int index, vector<int> &dp){
    //     if(index >= cost.size()){
    //         return 0;
    //     }
    //     if(dp[index] != -1){
    //         return dp[index];
    //     }
    //     return dp[index] = (cost[index] + min(solveMem(cost, index + 1, dp), solveMem(cost, index + 2, dp)));
    // }
    // int solveTab(vector<int>& cost, int index){
    //     int n = cost.size();
    //     vector<int> dp(n, 0);
    //     dp[n - 1] = cost[n - 1];
    //     for(int i = n - 2 ; i >= 0 ; i--){
    //         int temp = 0;
    //         if(i + 2 < n) temp = dp[i + 2];
    //         dp[i] = cost[i] + min(temp, dp[i + 1]);
    //     }
    //     return dp[index];
    // }
    int solveTabSO(vector<int>& cost, int index){
        int n = cost.size();
        int prev = cost[n - 1];
        int next = 0;
        int curr = cost[n - 1];

        for(int i = n - 2 ; i >= index ; i--){
            curr = cost[i] + min(prev, next);
            next = prev;
            prev = curr;
        }
        return curr;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(solveTabSO(cost, 0), solveTabSO(cost, 1));
    }
};