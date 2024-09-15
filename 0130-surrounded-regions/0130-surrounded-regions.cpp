class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>> &visited){
        visited[row][col] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int m = board.size();
        int n = board[0].size();
        for(int i = 0 ; i < 4 ; i++){
            int newRow = row + delrow[i];
            int newCol = col + delcol[i];
            if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && board[newRow][newCol] == 'O' && !visited[newRow][newCol]){
                dfs(newRow, newCol, board, visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        //checking first and last row
        for(int i = 0 ; i < n ; i++){
            //first row
            if(board[0][i] == 'O'){
                dfs(0, i, board, visited);
            }
            //last row
            if(board[m - 1][i] == 'O'){
                dfs(m - 1, i, board, visited);
            }
        }

        //checking first and last column
        for(int i = 0 ; i < m ; i++){
            //first column
            if(board[i][0] == 'O'){
                dfs(i, 0, board, visited);
            }
            //last column
            if(board[i][n - 1] == 'O'){
                dfs(i, n - 1, board, visited);
            }
        }

        //checking 'O' that are not marked
        for(int row = 1 ; row < m - 1 ; row++){
            for(int col = 1 ; col < n - 1 ; col++){
                if(board[row][col] == 'O' && !visited[row][col]){
                    board[row][col] = 'X';
                }
            }
        }
    }
};