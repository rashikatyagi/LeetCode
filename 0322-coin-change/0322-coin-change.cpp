class Solution {
public:
    // int solve(vector<int>& coins, int amount){
    //     if(amount == 0 ) return 0;
    //     if(amount < 0) return INT_MAX;
    //     int mini = INT_MAX;

    //     for(int i = 0 ; i < coins.size() ; i++){
    //         if(coins[i] <= amount){
    //             int recAns = solve(coins, amount - coins[i]);
    //             if(recAns != INT_MAX) recAns += 1;
    //             mini = min(recAns, mini);
    //         }
    //     }
    //     return mini;
    // }
    int solveMemo(vector<int>& coins, int amount, vector<int>&dp){
        if(amount == 0 ) return 0;
        if(amount < 0) return INT_MAX;
        int mini = INT_MAX;

        //check if answer already exists
        if(dp[amount] != -1)
            return dp[amount];

        for(int i = 0 ; i < coins.size() ; i++){
            if(coins[i] <= amount){
                int recAns = solveMemo(coins, amount - coins[i], dp);
                if(recAns != INT_MAX) recAns += 1;
                mini = min(recAns, mini);
            }
        }
        dp[amount] = mini;
        return mini;
    }
    int solveTab(vector<int>& coins, int amount){
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for(int val = 1 ; val <= amount ; val++){
            int mini = INT_MAX;
            for(int i = 0 ; i < coins.size() ; i++){
                if(coins[i] <= val){
                    int recAns = dp[val - coins[i]];
                    if(recAns != INT_MAX) recAns += 1;
                    mini = min(recAns, mini);
                }
            }
            dp[val] = mini;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solveTab(coins, amount);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};