class Solution {
public:
    // int solveRE(vector<int>& nums, int currIndex, int prevIndex){
    //     if(currIndex >= nums.size()){
    //         return 0;
    //     }
    //     // case of inclusion
    //     int ans1 = 0;
    //     if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]){
    //         ans1 = 1 + solveRE(nums, currIndex + 1, currIndex);
    //     }
    //     //case of exclusion
    //     int ans2 = solveRE(nums, currIndex + 1, prevIndex);
    //     return max(ans1, ans2);
    // }
    // int solveMem(vector<int>& nums, int currIndex, int prevIndex, vector<vector<int> > &dp){
    //     if(currIndex >= nums.size()){
    //         return 0;
    //     }

    //     // check if already present in dp or not
    //     if(dp[currIndex][prevIndex + 1] != -1){
    //         return dp[currIndex][prevIndex + 1];
    //     }

    //     // case of inclusion
    //     int ans1 = 0;
    //     if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]){
    //         ans1 = 1 + solveMem(nums, currIndex + 1, currIndex, dp);
    //     }
    //     //case of exclusion
    //     int ans2 = solveMem(nums, currIndex + 1, prevIndex, dp);
    //     return dp[currIndex][prevIndex + 1] = max(ans1, ans2);
    // }
    // int solveTab(vector<int>& nums){
    //     int n = nums.size();
    //     vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));

    //     for(int currIndex = n - 1 ; currIndex >= 0 ; currIndex--){
    //         for(int prevIndex = currIndex - 1 ; prevIndex >= -1 ; prevIndex--){
    //             int ans1 = 0;
    //             if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]){
    //                 ans1 = 1 + dp[currIndex + 1][currIndex + 1];
    //             }
    //             int ans2 = dp[currIndex + 1][prevIndex + 1];
    //             dp[currIndex][prevIndex + 1] = max(ans1, ans2);
    //         }
    //     }
    //     return dp[0][0];
    // }
    int solveTabSO(vector<int>& nums){
        int n = nums.size();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for(int currIndex = n - 1 ; currIndex >= 0 ; currIndex--){
            for(int prevIndex = currIndex - 1 ; prevIndex >= -1 ; prevIndex--){
                int ans1 = 0;
                if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]){
                    ans1 = 1 + prev[currIndex + 1];
                }
                int ans2 = prev[prevIndex + 1];
                curr[prevIndex + 1] = max(ans1, ans2);
            }
            prev = curr;
        }
        return curr[0];
    }
    int lengthOfLIS(vector<int>& nums) {
        return solveTabSO(nums);
    }
};