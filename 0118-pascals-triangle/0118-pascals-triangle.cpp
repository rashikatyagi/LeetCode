class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        if(numRows >= 1) triangle.push_back({1});
        if(numRows >= 2) triangle.push_back({1, 1});
        int currRow = 3;
        while(numRows-- > 2){
            vector<int> temp(currRow);
            for(int i = 0 ; i < currRow ; i++){
                if(i == 0 || i == currRow - 1){
                    temp[i] = 1;
                }
                else{
                    temp[i] = triangle[currRow - 2][i] + triangle[currRow - 2][i - 1];
                }
            }
            triangle.push_back(temp);
            currRow++;
        }
        return triangle;
    }
};