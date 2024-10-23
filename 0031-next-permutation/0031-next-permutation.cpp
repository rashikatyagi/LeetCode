class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        //step-1 get the dip : where first element is smaller than the next
        int index = -1;
        for(int i = n - 1 ; i > 0 ; i--){
            if(nums[i] > nums[i - 1]){
                index = i - 1;
                break;
            }
        }
        //if it is not found that means we are already at the end of the permutation we just need to reverse it
        if(index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        //step 2 get the smallest element greater than element at index
        for(int i = n - 1 ; i > index ; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        //step 3 reverse the remaining array
        reverse(nums.begin() + index + 1, nums.end());
    }
};