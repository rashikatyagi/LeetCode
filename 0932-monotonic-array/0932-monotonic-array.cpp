class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool ans1 = true;
        bool ans2 = true;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] < nums[i - 1]){
                ans1 = false;
                break;
            }
        }
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] > nums[i - 1]){
                ans2 = false;
                break;
            }
        }
        return ans1 || ans2;
    }
};