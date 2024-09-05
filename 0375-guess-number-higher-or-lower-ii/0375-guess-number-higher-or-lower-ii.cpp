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
    int solveTab(int n){
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));
        for(int start = n - 1 ; start >= 1 ; start--){
            for(int end = 1 ; end <= n ; end++){
                if(start >= end){
                    //invalid case
                    continue;
                }
                int ans = INT_MAX;
                for(int i = start ; i <= end ; i++){
                    ans = min(ans, i + max(dp[i + 1][end], dp[start][i - 1]));
                }
                dp[start][end] = ans;
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        return solveTab(n);
    }
};