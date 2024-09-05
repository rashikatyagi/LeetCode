class Solution {
public:
    int solveRE(vector<int>& arr, map< pair<int, int>, int > &mp, int start, int end){
        //base case
        if(start > end){
            return 0;
        }
        if(start == end){
            //leaf node
            return 0;
        }
        int ans = INT_MAX; //minimum answer is required
        for(int i = start ; i < end ; i++){
            //let i be the partition
            ans = min(ans, (mp[{start, i}] * mp[{i + 1, end}]) + solveRE(arr, mp, start, i) + solveRE(arr, mp, i + 1, end));
        }
        return ans;
    }
    int solveMem(vector<int>& arr, map< pair<int, int>, int > &mp, int start, int end, vector<vector<int> > &dp){
        //base case
        if(start >= end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int ans = INT_MAX; //minimum answer is required
        for(int i = start ; i < end ; i++){
            //let i be the partition
            ans = min(ans, (mp[{start, i}] * mp[{i + 1, end}]) 
            + solveMem(arr, mp, start, i, dp) + solveMem(arr, mp, i + 1, end, dp));
        }
        return dp[start][end] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        //storing maximum vales of all ranges as pre computation
        int n = arr.size();
        map< pair<int, int>, int > mp;
        for(int i = 0 ; i < n ; i++){
            mp[{i, i}] = arr[i];
            for(int j = i + 1 ; j < n ; j++){
                mp[{i, j}] = max(mp[{i, j - 1}], arr[j]);
            }
        }
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
        return solveMem(arr, mp, 0, n - 1, dp);
    }
};