class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefixSum = 0, answer = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            prefixSum += nums[i];
            int remove = prefixSum - goal;
            answer += mp[remove];
            mp[prefixSum]++;
        }
        return answer;
    }
};