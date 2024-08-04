class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        int i = 0, j = 0;
        int sum = nums[0];
        while(i < n && j < n){
            sum += (i == j) ? 0 : nums[j];
            ans.push_back(sum);
            j++;
            if(j == n){
                i++;
                j = i;
                if(i < n) sum = nums[i];
            }
        }
        sort(ans.begin(), ans.end());
        sum = 0;
        for(int i = left - 1 ; i < right ; i++){
            sum = (sum + ans[i]) % (1000000007);
        }
        return sum;
    }
};