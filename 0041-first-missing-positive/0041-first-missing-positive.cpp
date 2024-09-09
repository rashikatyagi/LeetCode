class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]] = i;
        }
        int max_element = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] > 0)
                max_element = max(max_element, nums[i]);
        }
        if(max_element == INT_MIN) return 1;
        for(int i = 1 ; i <= max_element; i++){
            if(mp.find(i) == mp.end()) return i;
        }
        return max_element + 1;
    }
};