class Solution {
public:
    // int solveRE(int n){
    //     if(n == 0 || n == 1) return n;
    //     if(n == 2) return 1;
    //     return solveRE(n - 1) + solveRE(n - 2) + solveRE(n - 3);
    // }
    int solveMem(int n, vector<int>&dp){
        if(n == 0 || n == 1) return n;
        if(n == 2) return 1;

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = solveMem(n - 1, dp) + solveMem(n - 2, dp) + solveMem(n - 3, dp);
        return dp[n];
    }
    int tribonacci(int n) {
        vector<int> dp(n + 1, -1);
        return solveMem(n, dp);
    }
};