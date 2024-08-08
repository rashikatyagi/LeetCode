class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int sr, int sc) {
        vector<vector<int>> ans;
        int it = 1;
        int count = 1;
        int total = rows * cols;
        ans.push_back({sr, sc});
        while(count < total){
            for(int i = 1 ; count < total && i <= it ; i++){
                sc++;
                if(sr >= 0 && sr < rows && sc >= 0 && sc < cols){
                    ans.push_back({sr, sc});
                    if(++count == total) return ans;
                }
            }
            for(int i = 1 ; count < total && i <= it ; i++){
                sr++;
                if(sr >= 0 && sr < rows && sc >= 0 && sc < cols){
                    ans.push_back({sr, sc});
                    if(++count == total) return ans;
                }
            }
            it++;
            for(int i = 1 ; count < total && i <= it ; i++){
                sc--;
                if(sr >= 0 && sr < rows && sc >= 0 && sc < cols){
                    ans.push_back({sr, sc});
                    if(++count == total) return ans;
                }
            }
            for(int i = 1; count < total && i <= it ; i++){
                sr--;
                if(sr >= 0 && sr < rows && sc >= 0 && sc < cols){
                    ans.push_back({sr, sc});
                    if(++count == total) return ans;
                }
            }
            it++;
        }
        return ans;
    }
};