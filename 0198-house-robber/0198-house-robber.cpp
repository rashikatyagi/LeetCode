class Solution {
public:
    //
    //     int solve(vector<int> &nums, int size, int index){
    //     if(index >= size) return 0;

    //     //chori ki
    //     int ans1 = nums[index] + solve(nums, size, index + 2);

    //     //chori nahi ki
    //     int ans2 = solve(nums, size, index + 1);
    //     return max(ans1, ans2); 
    // }
    // int robUsingMem(vector<int> &nums, int size, int index, vector<int> &dp){
    //     if(index >= size) return 0;

    //     if(dp[index] != -1){
    //         return dp[index];
    //     }

    //     //chori ki
    //     int ans1 = nums[index] + robUsingMem(nums, size, index + 2, dp);

    //     //chori nahi ki
    //     int ans2 = robUsingMem(nums, size, index + 1, dp);
    //     dp[index] =  max(ans1, ans2);
    //     return dp[index]; 
    // }
    int robUsingTab(vector<int> &nums, int n){
        //Step 1 create dp array
        vector<int> dp(n, -1);
        //Step 2 manually insert data
        dp[n - 1] = nums[n - 1];
        //Step 3 using logic of memoization method, iteratively solve
        for(int i = n - 2 ; i >= 0 ; i--){
            int temp = 0;
            if(i + 2 < n)
                temp = dp[i + 2];
            //chori ki
            int ans1 = nums[i] + temp;

            //chori nahi ki
            int ans2 = dp[i + 1];
            dp[i] = max(ans1, ans2);
        } 
        return dp[0];
    }
    int rob(vector<int>& nums) {
        return robUsingTab(nums, nums.size());
    }
};