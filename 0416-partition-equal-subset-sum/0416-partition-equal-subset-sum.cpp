class Solution {
public:
    // bool solveRE(vector<int>& nums, int index, int currsum, int &target){
    //     int n = nums.size();
    //     //base cases
    //     if(currsum == target){
    //         return true;
    //     }
    //     if(currsum > target){
    //         return false;
    //     }
    //     if(index >= n){
    //         return false;
    //     }
    //     bool inclusion = solveRE(nums, index + 1, currsum + nums[index], target);
    //     bool exclusion = solveRE(nums, index + 1, currsum, target);
    //     return inclusion || exclusion;
    // }
    bool solveMEM(vector<int>& nums, int index, int currsum, int &target, vector<vector<int> > &dp){
        int n = nums.size();
        //base cases
        if(currsum == target){
            return true;
        }
        if(currsum > target){
            return false;
        }
        if(index >= n){
            return false;
        }
        if(dp[index][currsum] != -1){
            return dp[index][currsum];
        }
        bool inclusion = solveMEM(nums, index + 1, currsum + nums[index], target, dp);
        bool exclusion = solveMEM(nums, index + 1, currsum, target, dp);
        dp[index][currsum] = inclusion || exclusion;
        return dp[index][currsum];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;
        for(int i = 0 ; i < n ; i++){
            totalsum += nums[i];
        }
        int target;
        //if the sum is odd then we cannot divide it into two parts
        if(totalsum & 1){
            return false;
        }
        else{
            target = totalsum / 2;
        }
        vector<vector<int> > dp(n + 1, vector<int>(totalsum + 1, -1));
        return solveMEM(nums, 0, 0, target, dp);
    }
};