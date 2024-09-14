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
    int solveMEM(int row, int col, int m, int n, vector<vector<int> > &dp){
        if(row == m - 1 && col == n - 1){
            return 1;
        }
        if(row >= m || col >= n){
            return 0;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        return dp[row][col] = solveMEM(row + 1, col, m, n, dp) + solveMEM(row, col + 1, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
        return solveMEM(0, 0, m, n, dp);
    }
};