class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        // number and set bits mapping
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto it : nums){
            int number = it;
            int count = 0;
            while(number){
                if(number % 2) count++;
                number = number / 2;
            }
            mp[it] = count;
        }
        for(int i = 0 ; i < n - 1 ; i++){
            bool flag = false;
            for(int j = 0 ; j < n - i - 1 ; j++){
                if(nums[j] > nums[j + 1] && mp[nums[j]] == mp[nums[j + 1]]){
                    flag = true;
                    swap(nums[j], nums[j + 1]);
                }
            }
            if(!flag) break;
        }
        for(int i = 0 ; i < n - 1 ; i++){
            cout << nums[i] << " ";
            if(nums[i] > nums[i + 1]) return false;
        }
        return true;
    }
};