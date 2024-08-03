class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size() ;
        int i = 0;
        int j = n - 1;
        int k = 0;
        while(k <= j){
            if(nums[k] == 0){
                swap(nums[k++], nums[i++]);
            }
            else if(nums[k] == 2){
                swap(nums[k], nums[j--]);
            }
            else k++;
        }
    }
};