class Solution {
public:
    void bfs(int row, int col, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1;
        while(!q.empty()){
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            if(currRow - 1 >= 0 && !visited[currRow - 1][currCol] && grid[currRow - 1][currCol]){
                q.push({currRow - 1, currCol});
                visited[currRow - 1][currCol] = 1;
            }
            if(currRow + 1 < m && !visited[currRow + 1][currCol] && grid[currRow + 1][currCol]){
                q.push({currRow + 1, currCol});
                visited[currRow + 1][currCol] = 1;
            }
            if(currCol - 1 >= 0 && !visited[currRow][currCol - 1] && grid[currRow][currCol - 1]){
                q.push({currRow, currCol - 1});
                visited[currRow][currCol - 1] = 1;
            }
            if(currCol + 1 < n && !visited[currRow][currCol + 1] && grid[currRow][currCol + 1]){
                q.push({currRow, currCol + 1});
                visited[currRow][currCol + 1] = 1;
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, 0));
        for(int row = 0 ; row < m ; row++){
            if(grid[row][0] == 1 && visited[row][0] == 0){
                bfs(row, 0, m, n, grid, visited);
            }
            if(grid[row][n - 1] == 1 && visited[row][n - 1] == 0){
                bfs(row, n - 1, m, n, grid, visited);
            }
        }
        for(int col = 0 ; col < n ; col++){
            if(grid[0][col] && visited[0][col] == 0){
                bfs(0, col, m, n, grid, visited);
            }
            if(grid[m - 1][col] && visited[m - 1][col] == 0){
                bfs(m - 1, col, m, n, grid, visited);
            }
        }
        int count = 0;
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col] == 1 && visited[row][col] == 0) count++;
            }
        }
        return count;
    }
};