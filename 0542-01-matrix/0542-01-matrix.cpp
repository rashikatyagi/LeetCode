class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int, int>, int> > q;
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        vector<vector<int>> answer(m, vector<int>(n, 0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        while(!q.empty()){
            int frontRow = q.front().first.first;
            int frontCol = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            answer[frontRow][frontCol] = dist;
            
            for(int i = 0 ; i < 4 ; i++){
                int newRow = frontRow + delrow[i];
                int newCol = frontCol + delcol[i];
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, dist + 1});
                }
            }
        }
        return answer;
    }
};