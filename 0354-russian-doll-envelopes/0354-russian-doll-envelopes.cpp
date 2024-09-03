class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int solveBinarySearch(vector<vector<int>>& nums){
        // sort the array
        sort(nums.begin(), nums.end(), compare);
        for(auto it : nums){
            cout << it[0] << " " << it[1] << endl;
        }
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0][1]);
        for(int i = 1 ; i < n ; i++){
            if(nums[i][1] > ans.back()){
                ans.push_back(nums[i][1]);
            }
            else{
                //get the index that have just greater element than the current element
                int index = lower_bound(ans.begin(), ans.end(), nums[i][1]) - ans.begin();
                ans[index] = nums[i][1];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        return solveBinarySearch(envelopes);
    }
};