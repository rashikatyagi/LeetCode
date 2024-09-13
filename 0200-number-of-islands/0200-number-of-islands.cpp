class Solution {
public:
    void bfs(int row, int col, vector<vector<bool>> &visited, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        //push the starting node in the queue and mark it visited
        q.push({row, col});
        visited[row][col] = 1;
        while(!q.empty()){
            auto frontNode = q.front();
            int frontRow = frontNode.first;
            int frontCol = frontNode.second;
            q.pop();
            //UP
            if(frontRow - 1 >= 0 && grid[frontRow - 1][frontCol] == '1' && !visited[frontRow - 1][frontCol]){
                q.push({frontRow - 1, frontCol});
                visited[frontRow - 1][frontCol] = 1;                
            }
            //DOWN
            if(frontRow + 1 < grid.size() && grid[frontRow + 1][frontCol] == '1' && !visited[frontRow + 1][frontCol]){
                q.push({frontRow + 1, frontCol});
                visited[frontRow + 1][frontCol] = 1;
            }
            //LEFT
            if(frontCol - 1 >= 0 && grid[frontRow][frontCol - 1] == '1' && !visited[frontRow][frontCol - 1]){
                q.push({frontRow, frontCol - 1});
                visited[frontRow][frontCol -1] = 1;
            }
            //RIGHT
            if(frontCol + 1 < grid[0].size() && grid[frontRow][frontCol + 1] == '1' && !visited[frontRow][frontCol + 1]) {
                q.push({frontRow, frontCol + 1});
                visited[frontRow][frontCol + 1] = 1;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //create a visited 2D array
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int answer = 0;
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == '1' && visited[row][col] == 0){
                    answer++;
                    bfs(row, col, visited, grid);
                }
            }
        }
        return answer;
    }
};