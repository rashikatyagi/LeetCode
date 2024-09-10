class Solution {
public:
    int maxOperations(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1) return 0;
	    sort(nums.begin(), nums.end());
        int start = 0; 
        int end = n - 1;
        int operations = 0;
        while(start < end){
            if(nums[start] + nums[end] == target){
                operations++;
                start++;
                end--;
            }
            else if(nums[start] + nums[end] < target){
                start++;
            }
            else{
                end--;
            }
        }
        return operations;

    }
};