class Solution {
public:
    // int solveRE(int row, int col, vector<vector<int>>& matrix){
    //     int n = matrix.size();
    //     // base case 
    //     if(row == n){
    //         return 0;
    //     }
    //     int final_ans = INT_MAX;
    //     if(col == -1){
    //         for(int i = 0 ; i < n ; i++){
    //             int recAns = matrix[row][i] + solveRE(row + 1, i, matrix);
    //             final_ans = min(final_ans, recAns);
    //         }
    //     }
    //     else{
    //         for(int i = -1 ; i <= 1 ; i++){
    //             if(col + i >= 0 && col + i < n){
    //                 int recAns = matrix[row][col + i] + solveRE(row + 1, col + i, matrix);
    //                 final_ans = min(final_ans, recAns);
    //             }
    //         }
    //     }
    //     return final_ans;
    // }
    // int solveMEM(int row, int col, vector<vector<int>>& matrix, vector<vector<int>> &dp){
    //     int n = matrix.size();
    //     // base case 
    //     if(row == n){
    //         return 0;
    //     }
    //     if(dp[row][col + 1] != -1){
    //         return dp[row][col + 1];
    //     }
    //     int final_ans = INT_MAX;
    //     if(col == -1){
    //         for(int i = 0 ; i < n ; i++){
    //             int recAns = matrix[row][i] + solveMEM(row + 1, i, matrix, dp);
    //             final_ans = min(final_ans, recAns);
    //         }
    //     }
    //     else{
    //         for(int i = -1 ; i <= 1 ; i++){
    //             if(col + i >= 0 && col + i < n){
    //                 int recAns = matrix[row][col + i] + solveMEM(row + 1, col + i, matrix, dp);
    //                 final_ans = min(final_ans, recAns);
    //             }
    //         }
    //     }
    //     return dp[row][col + 1] = final_ans;
    // }
    int solveTAB(vector<vector<int>>& matrix){
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        //base case -> last row remains same
        for(int i = 0 ; i < n ; i++){
            dp[n - 1][i] = matrix[n - 1][i];
        }

        for(int row = n - 2 ; row >= 0 ; row--){
            for(int col = 0 ; col < n ; col++){
                int final_ans = INT_MAX;

                //DOWN
                final_ans = min(final_ans, matrix[row][col] + dp[row + 1][col]);

                //DIAGONAL LEFT
                if(col - 1 >= 0){
                    final_ans = min(final_ans, matrix[row][col] + dp[row + 1][col - 1]);
                }

                //DIAGONAL RIGHT
                if(col + 1 < n){
                    final_ans = min(final_ans, matrix[row][col] + dp[row + 1][col + 1]);
                }

                dp[row][col] = final_ans;
            }
        }
        int answer = INT_MAX;
        //checking the minimum answer from the top row ie the 0th row
        for(int col = 0 ; col < n ; col++){
            answer = min(answer, dp[0][col]);
        }
        return answer;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solveTAB(matrix);
    }
};