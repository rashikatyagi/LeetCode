class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int currSum = 0;
            for(int j = i ; j < n ; j++){
                currSum += nums[j];
                if(currSum == goal){
                    ans++;
                }
                else if(currSum > goal) break;
            }
        }
        return ans;
    }
};