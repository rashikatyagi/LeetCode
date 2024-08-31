class Solution {
public:
    // int longestCommonSubsequenceRE(string text1, string text2, int i, int j) {
    //     //base case
    //     if(i >= text1.length() || j >= text2.length()){
    //         return 0;
    //     }
    //     //recursive calls
    //     int ans;
    //     if(text1[i] == text2[j]){
    //         ans = 1 + longestCommonSubsequenceRE(text1, text2, i + 1, j + 1);
    //     }
    //     else{
    //         ans = max(longestCommonSubsequenceRE(text1, text2, i, j + 1),
    //         longestCommonSubsequenceRE(text1, text2, i + 1, j));
    //     }
    //     return ans;
    // }
    // int longestCommonSubsequenceMem(string text1, string text2, int i, int j, vector<vector<int>> &dp) {
    //     //base case
    //     if(i >= text1.length() || j >= text2.length()){
    //         return 0;
    //     }
        
    //     //check whether answer exists or not
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     //recursive calls
    //     int ans;
    //     if(text1[i] == text2[j]){
    //         ans = 1 + longestCommonSubsequenceMem(text1, text2, i + 1, j + 1, dp);
    //     }
    //     else{
    //         ans = max(longestCommonSubsequenceMem(text1, text2, i, j + 1, dp),
    //         longestCommonSubsequenceMem(text1, text2, i + 1, j, dp));
    //     }
    //     dp[i][j] = ans;
    //     return ans;
    // }
    int longestCommonSubsequenceTab(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = m - 1 ; j >= 0 ; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else{
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int ans = longestCommonSubsequenceTab(text1, text2);
        return ans;
    }
};