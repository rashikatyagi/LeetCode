class Solution {
public:
    // bool solveRE(string &s, string &p, int i, int j){
    //     //base case
    //     if(i < 0 && j < 0){
    //         return true;
    //     }
    //     if(j < 0 && i >= 0){
    //         return false;
    //     }
    //     if(i < 0 && j >= 0){
    //         for(int it = 0 ; it <= j ; it++){
    //             if(p[it] != '*') return false;
    //         }
    //         return true;
    //     }

    //     if(s[i] == p[j] || p[j] == '?'){
    //         return solveRE(s, p, i - 1, j - 1);
    //     }
    //     if(p[j] == '*'){
    //         return solveRE(s, p, i - 1, j) || solveRE(s, p, i, j - 1);
    //     }
    //     return false;
    // }
    bool solveMEM(string &s, string &p, int i, int j, vector<vector<int> > &dp){
        //base case
        if(i < 0 && j < 0){
            return true;
        }
        if(j < 0 && i >= 0){
            return false;
        }
        if(i < 0 && j >= 0){
            for(int it = 0 ; it <= j ; it++){
                if(p[it] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solveMEM(s, p, i - 1, j - 1, dp);
        }
        if(p[j] == '*'){
            return dp[i][j] = solveMEM(s, p, i - 1, j, dp) || solveMEM(s, p, i, j - 1, dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int> > dp(n, vector<int> (m, -1));
        return solveMEM(s, p, n - 1, m - 1, dp);
    }
};