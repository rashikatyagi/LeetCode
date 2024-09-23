class Solution {
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n,
    vector<int> &leftCheck, vector<int> &upperDia, vector<int> &lowerDia) {
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0 ; row < n ; row++){
            if(leftCheck[row] == 0 && upperDia[row + col] == 0 && 
            lowerDia[n - 1 + col - row] == 0){
                board[row][col] = 'Q';
                leftCheck[row] = 1;
                upperDia[row + col] = 1;
                lowerDia[n - 1 + col - row] = 1;
                solve(col + 1, board, ans, n, leftCheck, upperDia, lowerDia);
                board[row][col] = '.';
                leftCheck[row] = 0;
                upperDia[row + col] = 0;
                lowerDia[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0 ; i < n ; i++){
            board[i] = s;
        }
        vector<vector<string>> ans;
        vector<int> leftCheck(n, 0);
        vector<int> upperDia(2 * n - 1, 0);
        vector<int> lowerDia(2 * n - 1, 0);
        solve(0, board, ans, n, leftCheck, upperDia, lowerDia);
        return ans;
    }
};