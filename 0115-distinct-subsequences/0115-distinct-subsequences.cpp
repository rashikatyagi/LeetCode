class Solution {
public:
    // int solveRE(string s, string t, int i, int j){
    //     if(j < 0) return 1; 
    //     if(i < 0) return 0;
    //     if(s[i] == t[j]){
    //         return (solveRE(s, t, i - 1, j - 1) + solveRE(s, t, i - 1, j));
    //     }
    //     else{
    //         return solveRE(s, t, i - 1, j);
    //     }
    // }
    int solveMEM(string s, string t, int i, int j, vector<vector<int>> &dp){
        if(j < 0) return 1; 
        if(i < 0) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            return dp[i][j] = (solveMEM(s, t, i - 1, j - 1, dp) + solveMEM(s, t, i - 1, j, dp));
        }
        else{
            return dp[i][j] = solveMEM(s, t, i - 1, j, dp);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solveMEM(s, t, n - 1, m - 1, dp);
    }
};