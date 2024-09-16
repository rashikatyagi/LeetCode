class Solution {
public:
    void solveTAB(string str1, string str2, vector<vector<int>> &dp){
        int n = str1.length(), m = str2.length();
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = m - 1 ; j >= 0 ; j--){
                if(str1[i] == str2[j]){
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        solveTAB(str1, str2, dp);
        
        int i = 0, j = 0;
        string ans = "";
        while(i < n && j < m){
            if(str1[i] == str2[j]){
                ans += str1[i];
                i++; j++;
            }   
            else if(dp[i + 1][j] >= dp[i][j + 1]) {
                ans += str1[i++];
            }
            else if(j + 1 < m){
                ans += str2[j++];
            }
        }
        while(i < n){
            ans += str1[i++];
        }
        while(j < m){
            ans += str2[j++];
        }

        return ans;
    }
};