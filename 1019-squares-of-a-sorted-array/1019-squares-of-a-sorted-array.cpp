class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        int k = n - 1;
        int num1 = nums[i] * nums[i];
        int num2 = nums[j] * nums[j];
        vector<int> ans(n);
        while(i <= j){
            if(num1 > num2){
                ans[k--] = num1;
                i++;
                if(i < n) num1 = nums[i] * nums[i];
            }
            else{
                ans[k--] = num2;
                j--;
                if(j >= 0) num2 = nums[j] * nums[j];
            }
        }
        return ans;
    }
};