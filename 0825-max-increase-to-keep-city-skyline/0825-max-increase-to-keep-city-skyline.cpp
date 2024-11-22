class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rowmax(n, 0);
        vector<int> colmax(n, 0);
        for(int row = 0 ; row < n ; row++){
            int maximum = grid[row][0];
            for(int col = 1 ; col < n ; col++){
                maximum = max(maximum, grid[row][col]);
            }
            rowmax[row] = maximum;
        }
        for(int col = 0 ; col < n ; col++){
            int maximum = grid[0][col];
            for(int row = 1 ; row < n ; row++){
                maximum = max(maximum, grid[row][col]);
            }
            colmax[col] = maximum;
        }
        int answer = 0;
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                int newHeight = min(rowmax[row], colmax[col]);
                answer += (newHeight - grid[row][col]);
            }
        }
        return answer;
    }
};