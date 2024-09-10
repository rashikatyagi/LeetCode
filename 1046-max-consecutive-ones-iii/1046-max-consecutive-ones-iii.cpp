class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int length = 0;
        int maxLength = 0;
        int zeros = 0;
        int n = nums.size();
        while(right < n){
            if(nums[right] == 0){
                zeros++;
                while(zeros > k){
                    if(nums[left] == 0) zeros--;
                    left++;
                }
            }
            length = right - left + 1;
            maxLength = max(maxLength, length);
            right++;   
        }
        return maxLength;
    }
    
};