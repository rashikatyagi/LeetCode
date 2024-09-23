class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n){
        int tempRow = row;
        int tempCol = col;
        // upper left diagonal check
        while(row >= 0 && col >= 0){
            if(board[row--][col--] == 'Q') return false;
        }
        row = tempRow;
        col = tempCol;
        //left direction check
        while(col >= 0){
            if(board[row][col--] == 'Q') return false;
        }
        col = tempCol;
        // downwards left diagonal check
        while(row < n && col >= 0){
            if(board[row++][col--] == 'Q') return false;
        }
        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int i = 0 ; i < n ; i++){
            if(isSafe(i, col, board, n)){
                board[i][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[i][col] = '.';
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
        solve(0, board, ans, n);
        return ans;
    }
};