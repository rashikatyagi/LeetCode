class Solution {
public:
    // int climbStairsRE(int n) {
    //     if(n == 1 || n == 2) return n;
    //     return climbStairsRE(n - 1) + climbStairsRE(n - 2);
    // }
    int climbStairsMem(int n, vector<int> &dp) {
        if(n == 1 || n == 2) return n;
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = climbStairsMem(n - 1, dp) + climbStairsMem(n - 2, dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return climbStairsMem(n, dp);
    }
};