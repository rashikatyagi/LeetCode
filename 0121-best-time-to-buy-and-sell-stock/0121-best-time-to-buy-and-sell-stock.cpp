class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minimum = prices[0];
        for(int i = 1 ; i < prices.size() ; i++){
            int tempProfit = prices[i] - minimum;
            if(tempProfit > profit) profit = tempProfit;
            if(prices[i] < minimum) minimum = prices[i];
        }
        return profit;
    }
};