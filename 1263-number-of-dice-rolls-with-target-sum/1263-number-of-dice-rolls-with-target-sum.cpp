class Solution {
public:
    long long int MOD = 1000000007;
    int solveRE(int n, int k, int target){
        //base cases
        if(target == 0 && n == 0){  //got the answer
            return 1;
        }
        if(target == 0 && n != 0){
            return 0;
        }
        if(n == 0 && target != 0){
            return 0;
        }
        int ans = 0;
        for(int i = 1 ; i <= k ; i++){
            if(target - i >= 0){
                ans += solveRE(n - 1, k, target - i);
            }
        }
        return ans;
    }
    int solveMem(int n, int k, int target, vector<vector<int> > &dp){
        //base cases
        if(target == 0 && n == 0){  //got the answer
            return 1;
        }
        if(target == 0 && n != 0){
            return 0;
        }
        if(n == 0 && target != 0){
            return 0;
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        int ans = 0;
        for(int i = 1 ; i <= k ; i++){
            if(target - i >= 0){
                ans = ((ans % MOD) + (solveMem(n - 1, k, target - i, dp)) % MOD) % MOD;
            }
        }
        return dp[n][target] = ans;
    }    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int> > dp(n + 1, vector<int>(target + 1, -1));
        return solveMem(n, k, target, dp);
    }
};