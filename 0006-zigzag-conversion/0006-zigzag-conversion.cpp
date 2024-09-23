class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        int index = 0;
        int col = 0;
        int n = s.length();
        vector<vector<char>> arr(numRows, vector<char>(n / 2 + 1, 0));
        while(index < n){
            for(int i = 0 ; i < numRows ; i++){
                if(index < n){
                    arr[i][col] = s[index++];
                }
                else break;
            }
            col++;
            for(int i = numRows - 2 ; i > 0 ; i--){
                if(index < n){
                    arr[i][col++] = s[index++];
                }
                else break;
            }
        }
        string ans = "";
        for(int i = 0 ; i < numRows ; i++){
            for(int j = 0 ; j <= (n / 2) ; j++){
                if(arr[i][j] != 0){
                    ans += arr[i][j];
                }
            }
        }
        return ans;
    }
};