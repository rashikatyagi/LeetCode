class Solution {
public:
    // int solveRE(int row, int col, vector<vector<int>>& grid, int m, int n) {
    //     if(row == m - 1 && col == n - 1){
    //         return grid[row][col];
    //     }
    //     if(row >= m || col >= n){
    //         return INT_MAX;
    //     }
    //     return grid[row][col] + min(solveRE(row + 1, col, grid, m, n), solveRE(row, col + 1, grid, m, n));
    // }
    int solveMEM(int row, int col, vector<vector<int>>& grid, int m, int n, vector<vector<int> > &dp) {
        if(row == m - 1 && col == n - 1){
            return grid[row][col];
        }
        if(row >= m || col >= n){
            return INT_MAX;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        return dp[row][col] = grid[row][col] + min(solveMEM(row + 1, col, grid, m, n, dp), solveMEM(row, col + 1, grid, m, n, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
        return solveMEM(0, 0, grid, m, n, dp);
    }
};