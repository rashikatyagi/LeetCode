class Solution {
public:
    // int minDistanceRE(string word1, string word2, int i, int j) {
    //     // base case
    //     //in this function we are returning the number of operations
    //     if(i == word1.length()){   //case if word1 is smaller than word2
    //         return word2.length() - j;
    //     }
    //     if(j == word2.length()){   //case if word2 is smaller than word1
    //         return word1.length() - i;
    //     }
    //     //recursion
    //     if(word1[i] == word2[j]){   //no operation required
    //         return minDistanceRE(word1, word2, i + 1, j + 1);
    //     }
    //     else{
    //         //case for replacing - that means these indexes will now be same
    //         int replace = 1 + minDistanceRE(word1, word2, i + 1, j + 1);
    //         int deletion = 1 + minDistanceRE(word1, word2, i + 1, j);
    //         int insertion = 1 + minDistanceRE(word1, word2, i, j + 1);
    //         return min(replace, min(deletion, insertion));
    //     }
    // }
    int minDistanceMem(string &word1, string &word2, int i, int j, vector<vector<int> > &dp) {
        // base case
        //in this function we are returning the number of operations
        if(i == word1.length()){   //case if word1 is smaller than word2
            return word2.length() - j;
        }
        if(j == word2.length()){   //case if word2 is smaller than word1
            return word1.length() - i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        //recursion
        if(word1[i] == word2[j]){   //no operation required
            dp[i][j] = minDistanceMem(word1, word2, i + 1, j + 1, dp);
        }
        else{
            //case for replacing - that means these indexes will now be same
            int replace = 1 + minDistanceMem(word1, word2, i + 1, j + 1, dp);
            int deletion = 1 + minDistanceMem(word1, word2, i + 1, j, dp);
            int insertion = 1 + minDistanceMem(word1, word2, i, j + 1, dp);
            dp[i][j] = min(replace, min(deletion, insertion));
        }
        return dp[i][j];
    }
    int minDistanceTab(string &word1, string &word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        
        //manually adding base case
        for(int i = 0 ; i < n1 ; i++){
            dp[i][n2] = n1 - i;
        }
        for(int j = 0 ; j < n2 ; j++){
            dp[n1][j] = n2 - j;
        }

        for(int i = n1 - 1 ; i >= 0 ; i--){
            for(int j = n2 - 1 ; j >= 0 ; j--){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else{
                    int replace = 1 + dp[i + 1][j + 1];
                    int insertion = 1 + dp[i][j + 1];
                    int deletion = 1 + dp[i + 1][j];
                    dp[i][j] = min(replace, min(insertion, deletion));
                }
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        // vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return minDistanceTab(word1, word2);
    }
};