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
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return minDistanceMem(word1, word2, 0, 0, dp);
    }
};