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
    int solveMem(vector<int>& nums, int currIndex, int prevIndex, vector<vector<int> > &dp){
        if(currIndex >= nums.size()){
            return 0;
        }

        // check if already present in dp or not
        if(dp[currIndex][prevIndex + 1] != -1){
            return dp[currIndex][prevIndex + 1];
        }

        // case of inclusion
        int ans1 = 0;
        if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]){
            ans1 = 1 + solveMem(nums, currIndex + 1, currIndex, dp);
        }
        //case of exclusion
        int ans2 = solveMem(nums, currIndex + 1, prevIndex, dp);
        return dp[currIndex][prevIndex + 1] = max(ans1, ans2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int>(n + 1, -1));
        return solveMem(nums, 0, -1, dp);
    }
};