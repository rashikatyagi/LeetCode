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
    int robUsingMem(vector<int> &nums, int size, int index, vector<int> &dp){
        if(index >= size) return 0;

        if(dp[index] != -1){
            return dp[index];
        }

        //chori ki
        int ans1 = nums[index] + robUsingMem(nums, size, index + 2, dp);

        //chori nahi ki
        int ans2 = robUsingMem(nums, size, index + 1, dp);
        dp[index] =  max(ans1, ans2);
        return dp[index]; 
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return robUsingMem(nums, nums.size(), 0, dp);
    }
};