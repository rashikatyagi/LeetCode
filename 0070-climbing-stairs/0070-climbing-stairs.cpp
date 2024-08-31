class Solution {
public:
    // int climbStairsRE(int n) {
    //     if(n == 1 || n == 2) return n;
    //     return climbStairsRE(n - 1) + climbStairsRE(n - 2);
    // }
    // int climbStairsMem(int n, vector<int> &dp) {
    //     if(n == 1 || n == 2) return n;
    //     if(dp[n] != -1){
    //         return dp[n];
    //     }
    //     dp[n] = climbStairsMem(n - 1, dp) + climbStairsMem(n - 2, dp);
    //     return dp[n];
    // }
    // int climbStairsTab(int n) {
    //     if(n == 1 || n == 2) return n;
    //     vector<int> dp(n + 1, 0);
    //     dp[1] = 1;
    //     dp[2] = 2;
    //     for(int i = 3 ; i <= n ; i++){
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //     return dp[n];
    // }
    int climbStairsTabSO(int n) {
        if(n == 1 || n == 2) return n;
        int prev = 1;
        int next = 2;
        int curr;
        for(int i = 3 ; i <= n ; i++){
            curr = next + prev;
            prev = next;
            next = curr;
        }
        return curr;
    }
    int climbStairs(int n) {
        return climbStairsTabSO(n);
    }
};