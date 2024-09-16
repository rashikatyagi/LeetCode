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
    // int solveMEM(int index, bool buy, vector<int>& prices, vector<vector<int> > &dp){
    //     if(index == prices.size()){
    //         return 0;
    //     }
    //     if(dp[index][buy] != -1){
    //         return dp[index][buy];
    //     }
    //     int profit;
    //     if(buy){ //can buy
    //         profit = max(-prices[index] + solveMEM(index + 1, 0, prices, dp), solveMEM(index + 1, 1, prices, dp));
    //     }
    //     else{ //can sell
    //         profit = max(prices[index] + solveMEM(index + 1, 1, prices, dp), solveMEM(index + 1, 0, prices, dp));
    //     }
    //     return dp[index][buy] = profit;
    // }
    // int solveTAB(vector<int>& prices, int n){
    //     vector<vector<int> > dp(n, vector<int>(2, 0));
    //     dp[n - 1][0] = prices[n - 1];

    //     for(int index = n - 2 ; index >= 0 ; index--){
    //         for(int buy = 0 ; buy <= 1 ; buy++){
    //             int profit;
    //             if(buy){ //can buy
    //                 profit = max(-prices[index] + dp[index + 1][0], dp[index + 1][1]);
    //             }
    //             else{ //can sell
    //                 profit = max(prices[index] + dp[index + 1][1], dp[index + 1][0]);
    //             }

    //             dp[index][buy] = profit;
    //         }
    //     }
        
    //     return dp[0][1];
    // }
    int solveTAB(vector<int>& prices, int n){
        vector<int> curr(2, 0);
        vector<int> prev(2, 0);
        prev[0] = prices[n - 1];

        for(int index = n - 2 ; index >= 0 ; index--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit;
                if(buy){ //can buy
                    profit = max(-prices[index] + prev[0], prev[1]);
                }
                else{ //can sell
                    profit = max(prices[index] + prev[1], prev[0]);
                }

                curr[buy] = profit;
            }
            prev = curr;
        }
        return prev[1];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int> > dp(n, vector<int>(2, -1));
        // return solveRE(0, 1, prices);
        // return solveMEM(0, 1, prices, dp);
        return solveTAB(prices, n);
    }
};