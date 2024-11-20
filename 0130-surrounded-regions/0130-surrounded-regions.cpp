class Solution {
public:
    void dfs(int row, int col, int m, int n, vector<vector<char>>& board, vector<vector<bool>>& visited){
        visited[row][col] = 1;
        if(row - 1 >= 0 && board[row - 1][col] == 'O' && visited[row - 1][col] == 0){
            dfs(row - 1, col, m, n, board, visited);
        }
        if(row + 1 < m && board[row + 1][col] == 'O' && visited[row + 1][col] == 0){
            dfs(row + 1, col, m, n, board, visited);
        }
        if(col - 1 >= 0 && board[row][col - 1] == 'O' && visited[row][col - 1] == 0){
            dfs(row, col - 1, m, n, board, visited);
        }
        if(col + 1 < n && board[row][col + 1] == 'O' && visited[row][col + 1] == 0){
            dfs(row, col + 1, m, n, board, visited);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        for(int row = 0 ; row < m ; row++){
            if(board[row][0] == 'O'){
                dfs(row, 0, m, n, board, visited);
            }
            if(board[row][n - 1] == 'O'){
                dfs(row, n - 1, m, n, board, visited);
            }
        }
        for(int col = 0 ; col < n ; col++){
            if(board[0][col] == 'O'){
                dfs(0, col, m, n, board, visited);
            }
            if(board[m - 1][col] == 'O'){
                dfs(m - 1, col, m, n, board, visited);
            }
        }
        //convert all the Os that are not visited to X
        for(int row = 1 ; row < m - 1 ; row++){
            for(int col = 1 ; col < n - 1 ; col++){
                if(board[row][col] == 'O' && visited[row][col] == 0){
                    board[row][col] = 'X';
                }
            }
        }
    }
};