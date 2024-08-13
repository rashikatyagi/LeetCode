class Solution {
public:
    void solve(vector<int>& nums, int index, int target, vector<int> &temp, vector<vector<int> >&ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(index == nums.size()) return;
        int element = nums[index];
        if(target >= element){
            temp.push_back(element);
            solve(nums, index, target - element, temp, ans);
            temp.pop_back();
        }
        solve(nums, index + 1, target, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, 0, target, temp, ans);
        return ans;
    }
};