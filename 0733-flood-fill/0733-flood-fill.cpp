class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color, int initialcolor){
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            image[row][col] = color;
            if(row - 1 >= 0 && image[row - 1][col] == initialcolor) q.push({row - 1, col});
            if(row + 1 < m && image[row + 1][col] == initialcolor) q.push({row + 1, col});
            if(col - 1 >= 0 && image[row][col - 1] == initialcolor) q.push({row, col - 1});
            if(col + 1 < n && image[row][col + 1] == initialcolor) q.push({row, col + 1});
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialcolor = image[sr][sc];
        if(initialcolor == color) return image;
        bfs(image, sr, sc, color, initialcolor);
        return image;
    }
};