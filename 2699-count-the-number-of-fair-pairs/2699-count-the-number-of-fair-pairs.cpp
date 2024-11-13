class Solution {
public:
    long long getCount(vector<int>& nums, int target){
        // this function gives all the pairs whose sum is less than or equal to target
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        long long count = 0;
        while(left < right){
            if(nums[left] + nums[right] > target) right--;
            else{
                count += right - left;
                left++;
            }
        }
        return count;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return getCount(nums, upper) - getCount(nums, lower - 1);
    }
};