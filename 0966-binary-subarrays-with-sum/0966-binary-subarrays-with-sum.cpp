class Solution {
public:
    // this function gives the total subarrays having a 
    // sum of less than or equal to goal
    int solve(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int left = 0, right = 0;
        int currSum = 0;
        int answer = 0;
        while(right < nums.size()){
            currSum += nums[right];
            while(currSum > goal){
                currSum -= nums[left];
                left++;
            }
            int len = right - left + 1;
            answer += len;
            right++;
        }
        return answer;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans1 = solve(nums, goal);
        int ans2 = solve(nums, goal - 1);
        return ans1 - ans2;
    }
};