class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // <---------- NAIVE APPROACH ---------->
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // for(int i = 0 ; i < n - 1 ; i++)
        // {
        //     if(nums[i] == nums[i + 1])
        //         return nums[i];
        // }
        // return -1;

        // <---------- VISITED FLAG APPROACH ---------->
        // int n = nums.size();
        // int ans = -1;
        // for(int i = 0 ; i < n ; i++)
        // {
        //     if(nums[ abs(nums[i]) ] < 0)
        //     {
        //         return abs(nums[i]);
        //     }
        //     nums[ abs(nums[i]) ] *= ans;
        // }
        // return ans;

        // <---------- POSITIONING METHOD ----------->
        while(nums[0] != nums[nums[0]])
        {
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
};