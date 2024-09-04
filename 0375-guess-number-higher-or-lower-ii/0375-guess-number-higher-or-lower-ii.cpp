class Solution {
public:
    // int solve(int start, int end){
    //     if(start >= end){
    //         return 0;
    //     }
    //     int ans = INT_MAX;
    //     for(int i = start ; i <= end ; i++){
    //         ans = min(ans, i + max(solve(i + 1, end), solve(start, i - 1)));
    //     }
    //     return ans;
    // }
    int solveMem(int start, int end, vector<vector<int>> &dp){
        if(start >= end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int ans = INT_MAX;
        for(int i = start ; i <= end ; i++){
            ans = min(ans, i + max(solveMem(i + 1, end, dp), solveMem(start, i - 1, dp)));
        }
        return dp[start][end] = ans;
    }
    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solveMem(start, end, dp);
    }
};