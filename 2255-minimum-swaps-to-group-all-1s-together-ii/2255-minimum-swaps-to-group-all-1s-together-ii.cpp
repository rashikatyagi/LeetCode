class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        if(sum == 0 || sum == n) return 0;
        //concatenate the array
        vector<int> arr = nums;
        for(int i = 0 ; i < n ; i++){
            arr.push_back(nums[i]);
        }
        //number of 1 in first window
        int curr = 0;
        for(int i = 0 ; i < sum ; i++){
            curr += arr[i];
        }
        //for other windows get the window having maximum ones
        int max_sum = curr;
        for(int i = sum ; i < 2 * n ; i++){
            curr = curr + arr[i] - arr[i - sum];
            max_sum = max(max_sum, curr);
        }
        return sum - max_sum;
    }
};