class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int col = matrix[0].size();
        int startRow = 0;
        int endRow = rows - 1;
        int startCol = 0;
        int endCol = col - 1;
        int count = 0;  //to count total number of elements
        vector<int> ans;
        while(count < rows * col){
            for(int i = startCol ; count < rows * col && i <= endCol ; i++){
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;
            for(int i = startRow ; count < rows * col && i <= endRow ; i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;
            for(int i = endCol ; count < rows * col && i >= startCol ; i--){
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;
            for(int i = endRow ; count < rows * col && i >= startRow ; i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};