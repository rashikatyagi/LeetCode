class Solution {
public:
    int solve(vector<int> &nums, int index, bool check, vector<vector<int>> &dp){
        int n = nums.size();
        if(index >= n) return 0;
        if(index == n - 1){
            if(check) return 0;
            return nums[index];
        }
        if(dp[index][check] != -1){
            return dp[index][check];
        }
        int ans1;
        if(index == 0 || check) ans1 = nums[index] + solve(nums, index + 2, true, dp);
        else ans1 = nums[index] + solve(nums, index + 2, false, dp);
        int ans2;
        if(check) ans2 = solve(nums, index + 1, true, dp);
        else ans2 = solve(nums, index + 1, false, dp);
        dp[index][check] = max(ans1, ans2);
        return dp[index][check];
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, -1)); 
        return solve(nums, 0, false, dp);
    }
};