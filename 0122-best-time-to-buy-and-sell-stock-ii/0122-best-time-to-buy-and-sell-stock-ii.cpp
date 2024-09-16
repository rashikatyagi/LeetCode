class Solution {
public:
    // int solveRE(int index, bool buy, vector<int>& prices){
    //     if(index == prices.size()){
    //         return 0;
    //     }
    //     int profit;
    //     if(buy){ //can buy
    //         profit = max(-prices[index] + solveRE(index + 1, 0, prices), solveRE(index + 1, 1, prices));
    //     }
    //     else{ //can sell
    //         profit = max(prices[index] + solveRE(index + 1, 1, prices), solveRE(index + 1, 0, prices));
    //     }
    //     return profit;
    // }
    int solveMEM(int index, bool buy, vector<int>& prices, vector<vector<int> > &dp){
        if(index == prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        int profit;
        if(buy){ //can buy
            profit = max(-prices[index] + solveMEM(index + 1, 0, prices, dp), solveMEM(index + 1, 1, prices, dp));
        }
        else{ //can sell
            profit = max(prices[index] + solveMEM(index + 1, 1, prices, dp), solveMEM(index + 1, 0, prices, dp));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(n, vector<int>(2, -1));
        // return solveRE(0, 1, prices);
        return solveMEM(0, 1, prices, dp);
    }
};