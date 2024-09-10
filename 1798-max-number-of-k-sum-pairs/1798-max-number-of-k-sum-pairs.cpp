class Solution {
public:
    int maxOperations(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1) return 0;
	    unordered_map<int, int> mp;
	    for(int i = 0 ; i < n ; i++){
	        mp[nums[i]]++;
        }
        for(auto it : mp){
            cout << it.first << " : " << it.second << endl;
        }
        int operations = 0;
        for(int i = 0 ; i < n ; i++){
	        int element = target - nums[i];
            if(mp.find(nums[i]) != mp.end() && mp[nums[i]] > 0){
                mp[nums[i]]--;
	            if(mp.find(element) != mp.end() && mp[element] > 0){
		            operations++;
		            mp[element]--;
                }
            }
        }
        return operations;

    }
};