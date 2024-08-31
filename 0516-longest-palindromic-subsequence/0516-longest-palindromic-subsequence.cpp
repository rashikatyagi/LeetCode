class Solution {
public:
    // int longestPalindromeSubseqRE(string s, int start, int end) {
    //     //base case
    //     if(start == end){
    //         return 1;
    //     }    
    //     if(start > end){
    //         return 0;
    //     }
    //     int ans;
    //     if(s[start] == s[end]){
    //         ans = 2 + longestPalindromeSubseqRE(s, start + 1, end - 1);
    //     }
    //     else{
    //         ans = max(longestPalindromeSubseqRE(s, start, end - 1),
    //         longestPalindromeSubseqRE(s, start + 1, end));
    //     }
    //     return ans;
    // }
    // int longestPalindromeSubseqMem(string s, int start, int end, vector<vector<int>> &dp) {
    //     //base case
    //     if(start == end){
    //         return 1;
    //     }    
    //     if(start > end){
    //         return 0;
    //     }
    //     if(dp[start][end] != -1){
    //         return dp[start][end];
    //     }

    //     int ans;
    //     if(s[start] == s[end]){
    //         ans = 2 + longestPalindromeSubseqMem(s, start + 1, end - 1, dp);
    //     }
    //     else{
    //         ans = max(longestPalindromeSubseqMem(s, start, end - 1, dp),
    //         longestPalindromeSubseqMem(s, start + 1, end, dp));
    //     }
    //     dp[start][end] = ans;
    //     return ans;
    // }
    int longestPalindromeSubseqTab(string s){
        int n = s.length();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        // base case manual updation
        for(int i = 0 ; i < n ; i++){
            dp[i][i] = 1;
        }
        for(int j = 1 ; j < n ; j++){
            for(int i = j - 1 ; i >= 0 ; i--){
                if(s[i] == s[j]){
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
    int longestPalindromeSubseq(string s) {
        return longestPalindromeSubseqTab(s);
    }
};