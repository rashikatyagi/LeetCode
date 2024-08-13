class Solution {
public:
    void solve(vector<int>& nums, int index, int target, vector<int> &temp, vector<vector<int> >&ans){
        if(index == nums.size()) return;
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0) return;
        int element = nums[index];
        temp.push_back(element);
        solve(nums, index, target - element, temp, ans);
        temp.pop_back();
        solve(nums, index + 1, target, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, 0, target, temp, ans);
        return ans;
    }
};