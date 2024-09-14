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
    // int solveMEM(int row, int col, vector<vector<int>>& grid, int m, int n, vector<vector<int> > &dp) {
    //     if(row == m - 1 && col == n - 1){
    //         return grid[row][col];
    //     }
    //     if(row >= m || col >= n){
    //         return INT_MAX;
    //     }
    //     if(dp[row][col] != -1){
    //         return dp[row][col];
    //     }
    //     return dp[row][col] = grid[row][col] + min(solveMEM(row + 1, col, grid, m, n, dp), solveMEM(row, col + 1, grid, m, n, dp));
    // }
    int solveTAB(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        for(int row = m - 1 ; row >= 0 ; row--){
            for(int col = n - 1 ; col >= 0 ; col--){
                if(row == m - 1 && col == n - 1) continue;
                dp[row][col] = grid[row][col] + min(dp[row + 1][col], dp[row][col + 1]);
            }
        }
        return dp[0][0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        return solveTAB(grid);
    }
};