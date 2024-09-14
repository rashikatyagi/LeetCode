class Solution {
public:
    // int solveRE(int row, int col, int m, int n){
    //     if(row == m - 1 && col == n - 1){
    //         return 1;
    //     }
    //     if(row >= m || col >= n){
    //         return 0;
    //     }
    //     return solveRE(row + 1, col, m, n) + solveRE(row, col + 1, m, n);
    // }
    // int solveMEM(int row, int col, int m, int n, vector<vector<int> > &dp){
    //     if(row == m - 1 && col == n - 1){
    //         return 1;
    //     }
    //     if(row >= m || col >= n){
    //         return 0;
    //     }
    //     if(dp[row][col] != -1){
    //         return dp[row][col];
    //     }
    //     return dp[row][col] = solveMEM(row + 1, col, m, n, dp) + solveMEM(row, col + 1, m, n, dp);
    // }
    
    int solveTAB(int m, int n){
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        dp[m - 1][n - 1] = 1;
        for(int row = m - 1 ; row >= 0 ; row--){
            for(int col = n - 1 ; col >= 0 ; col--){
                if(row == m - 1 && col == n - 1) continue;
                dp[row][col] = dp[row + 1][col] + dp[row][col + 1];
            }
        }
        return dp[0][0];
    }
    int uniquePaths(int m, int n) {
        //vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
        return solveTAB(m, n);
    }
};