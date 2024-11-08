class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int xors = 0;
        for(int i = 0 ; i < n ; i++){
            xors = xors ^ nums[i];
        }
        int mask = ((1 << maximumBit) - 1);  //equivalent to 2^n - 1
        vector<int> result(n);
        for(int i = 0 ; i < n ; i++){
            int k = xors ^ mask;
            result[i] = k;
            xors = xors ^ nums[n - i - 1];
        }
        return result;
    }
};