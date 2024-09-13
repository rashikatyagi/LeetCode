class Solution {
public:
    void bfs(int row, int col, int pixel, vector<vector<int>>& image, vector<vector<bool>>& visited, int color) {
        queue<pair<int, int>> q;
        //color and visit the starting node
        image[row][col] = color;
        visited[row][col] = 1;
        q.push({row, col});
        while(!q.empty()){
            int frontRow = q.front().first;
            int frontCol = q.front().second;
            q.pop();
            if(frontRow - 1 >= 0 && image[frontRow - 1][frontCol] == pixel && !visited[frontRow - 1][frontCol]){
                visited[frontRow - 1][frontCol] = 1;
                image[frontRow - 1][frontCol] = color;
                q.push({frontRow - 1, frontCol});
            }
            if(frontRow + 1 < image.size() && image[frontRow + 1][frontCol] == pixel && !visited[frontRow + 1][frontCol]){
                visited[frontRow + 1][frontCol] = 1;
                image[frontRow + 1][frontCol] = color;
                q.push({frontRow + 1, frontCol});
            }
            if(frontCol - 1 >= 0 && image[frontRow][frontCol - 1] == pixel && !visited[frontRow][frontCol - 1]){
                visited[frontRow][frontCol - 1] = 1;
                image[frontRow][frontCol - 1] = color;
                q.push({frontRow, frontCol - 1});
            }
            if(frontCol + 1 < image[0].size() && image[frontRow][frontCol + 1] == pixel && !visited[frontRow][frontCol + 1]){
                visited[frontRow][frontCol + 1] = 1;
                image[frontRow][frontCol + 1] = color;
                q.push({frontRow, frontCol + 1});
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        if(image[sr][sc] == color) return image;
        vector<vector<bool> > visited(n, vector<bool>(m, false));
    
        //apply bfs
        bfs(sr, sc, image[sr][sc], image, visited, color);
        return image;
    }
};