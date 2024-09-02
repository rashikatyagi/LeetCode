class Solution {
public:
    // int solveRE(int n){
    //     if(n == 0 || n == 1) return n;
    //     if(n == 2) return 1;
    //     return solveRE(n - 1) + solveRE(n - 2) + solveRE(n - 3);
    // }
    // int solveMem(int n, vector<int>&dp){
    //     if(n == 0 || n == 1) return n;
    //     if(n == 2) return 1;

    //     if(dp[n] != -1){
    //         return dp[n];
    //     }

    //     dp[n] = solveMem(n - 1, dp) + solveMem(n - 2, dp) + solveMem(n - 3, dp);
    //     return dp[n];
    // }
    // int solveTab(int n){
    //     if(n == 0) return 0;
    //     vector<int> dp(n + 1, 0);
    //     dp[1] = 1;
    //     if(n == 1) return dp[n];
    //     dp[2] = 1;
    //     if(n == 2) return dp[n];

    //     for(int i = 3 ; i <= n ; i++){
    //         dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    //     }
    //     return dp[n];
    // }
    int solveTabSO(int n){
        int prev1 = 0;
        int prev2 = 1;
        int prev3 = 1;
        int curr;
        if(n == 0 || n == 1) return n;
        if(n == 2) return 1;
        for(int i = 3 ; i <= n ; i++){
            curr = prev1 + prev2 + prev3;
            prev1 = prev2;
            prev2 = prev3;
            prev3 = curr;
        }
        return curr;
    }
    int tribonacci(int n) {
        return solveTabSO(n);
    }
};