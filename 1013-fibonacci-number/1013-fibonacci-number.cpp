class Solution {
public:
    // Using Tabulation method
    int fib(int n) {
        // STEP 1 make dp array
        vector<int> dp(n + 1, -1);
        
        // STEP 2 enter manually some inital data using base cases of recursion
        dp[0] = 0;
        if(n == 0) return 0;
        //if n was zero then an array of 1 size would be made which will give segmentation fault at dp[1]
        dp[1] = 1;

        // STEP 3 fill the dp array using logic of recursive call of recursion
        for(int i = 2 ; i <= n ; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};