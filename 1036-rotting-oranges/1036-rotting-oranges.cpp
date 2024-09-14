class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //make a visited 2D matrix
        vector<vector<int>> visited(n, vector<int>(m, 0));
        //make a queue to store the initial rotten oranges
        //in queue -> {{row, col}, level/time}
        queue<pair<pair<int, int>, int> > q;

        //check the initial rotten oranges in the grid, 
        //store them in queue and mark them visited
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == 2){
                    q.push({{row, col}, 0});
                    visited[row][col] = 2;
                }
            }
        }
        //BFS
        int total_time = 0;
        while(!q.empty()){
            //extract row, column, time
            int currRow = q.front().first.first;
            int currCol = q.front().first.second;
            int time = q.front().second;
            //pop
            q.pop();

            //check in the 4 directions
            //UP
            if(currRow - 1 >= 0 && grid[currRow - 1][currCol] == 1 && !visited[currRow - 1][currCol]){
                visited[currRow - 1][currCol] = 2;
                q.push({{currRow - 1, currCol}, time + 1});
            }

            //DOWN
            if(currRow + 1 < n && grid[currRow + 1][currCol] == 1 && !visited[currRow + 1][currCol]){
                visited[currRow + 1][currCol] = 2;
                q.push({{currRow + 1, currCol}, time + 1});
            }

            //LEFT
            if(currCol - 1 >= 0 && grid[currRow][currCol - 1] == 1 && !visited[currRow][currCol - 1]){
                visited[currRow][currCol - 1] = 2;
                q.push({{currRow, currCol - 1}, time + 1});
            }

            //RIGHT
            if(currCol + 1 < m && grid[currRow][currCol + 1] == 1 && !visited[currRow][currCol + 1]){
                visited[currRow][currCol + 1] = 2;
                q.push({{currRow, currCol + 1}, time + 1});
            }
            total_time = time;
        }
        //check whether any orange is left fresh
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == 1 && visited[row][col] == 0) {
                    return -1;
                }
            }
        }
        return total_time;
    }
};