class Solution {
public:
    void bfs(int row, int col, int m, int n, vector<vector<char>>& board, vector<vector<bool>>& visited){
        queue<pair<int, int>> q;
        visited[row][col] = 1;
        q.push({row, col});
        while(!q.empty()){
            int newrow = q.front().first;
            int newcol = q.front().second;
            q.pop();
            if(newrow - 1 >= 0 && board[newrow - 1][newcol] == 'X' && visited[newrow - 1][newcol] == 0){
                visited[newrow - 1][newcol] = 1;
                q.push({newrow - 1, newcol});
            }
            if(newrow + 1 < m && board[newrow + 1][newcol] == 'X' && visited[newrow + 1][newcol] == 0){
                visited[newrow + 1][newcol] = 1;
                q.push({newrow + 1, newcol});
            }
            if(newcol - 1 >= 0 && board[newrow][newcol - 1] == 'X' && visited[newrow][newcol - 1] == 0){
                visited[newrow][newcol - 1] = 1;
                q.push({newrow, newcol - 1});
            }
            if(newcol + 1 < n && board[newrow][newcol + 1] == 'X' && visited[newrow][newcol + 1] == 0){
                visited[newrow][newcol + 1] = 1;
                q.push({newrow, newcol + 1});
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        int battleships = 0;
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(board[row][col] == 'X' && visited[row][col] == 0){
                    bfs(row, col, m, n, board, visited);
                    battleships++;
                }
            }
        }
        return battleships;
    }
};