class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for(int rows = 1 ; rows <= numRows ; rows++){
            vector<int> temp(rows);
            for(int j = 0 ; j < rows ; j++){
                if(j == 0 || j == rows - 1){
                    temp[j] = 1;
                }
                else{
                    temp[j] = triangle[rows - 2][j] + triangle[rows - 2][j - 1];
                }
            }
            triangle.push_back(temp);
        }
        return triangle;
    }
};