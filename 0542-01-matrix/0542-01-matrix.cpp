class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, 0));
        vector<vector<int>> distance(m, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>> q;
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(mat[row][col] == 0){
                    q.push({0, {row, col}});
                    visited[row][col] = 1;
                }
            }
        }
        while(!q.empty()){
            int dist = q.front().first;
            int currrow = q.front().second.first;
            int currcol = q.front().second.second;
            q.pop();
            distance[currrow][currcol] = dist;
            if(currrow - 1 >= 0 && visited[currrow - 1][currcol] == 0){
                q.push({dist + 1, {currrow - 1, currcol}});
                visited[currrow - 1][currcol] = 1;
            }
            if(currrow + 1 < m && visited[currrow + 1][currcol] == 0){
                q.push({dist + 1, {currrow + 1, currcol}});
                visited[currrow + 1][currcol] = 1;
            }
            if(currcol - 1 >= 0 && visited[currrow][currcol - 1] == 0){
                q.push({dist + 1, {currrow, currcol - 1}});
                visited[currrow][currcol - 1] = 1;
            }
            if(currcol + 1 < n && visited[currrow][currcol + 1] == 0){
                q.push({dist + 1, {currrow, currcol + 1}});
                visited[currrow][currcol + 1] = 1;
            }
        }
        return distance;
    }
};