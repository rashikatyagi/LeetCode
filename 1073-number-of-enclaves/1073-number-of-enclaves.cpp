class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>> &visited){
        visited[row][col] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0 ; i < 4 ; i++){
            int newRow = row + delrow[i];
            int newCol = col + delcol[i];
            if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] && !visited[newRow][newCol]){
                dfs(newRow, newCol, grid, visited);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //make a visited array
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        //check the first and last row for lands
        for(int i = 0 ; i < n ; i++){
            //first row
            if(grid[0][i] == 1){
                dfs(0, i, grid, visited);
            }
            //last row
            if(grid[m - 1][i] == 1){
                dfs(m - 1, i, grid, visited);
            }
        }
        //check the first and last column for lands
        for(int i = 0 ; i < m ; i++){
            //first column
            if(grid[i][0] == 1){
                dfs(i, 0, grid, visited);
            }
            //last column
            if(grid[i][n - 1] == 1){
                dfs(i, n - 1, grid, visited);
            }
        }
        //check the non boundary element, if they are land and still not visited
        int land_unvisited = 0;
        for(int row = 1 ; row < m - 1 ; row++){
            for(int col = 1 ; col < n - 1 ; col++){
                if(grid[row][col] == 1 && !visited[row][col]){
                    land_unvisited++;
                }
            }
        }
        return land_unvisited;
    }
};