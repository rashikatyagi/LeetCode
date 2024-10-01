class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        // store the remainders and their frequencies
        unordered_map<int, int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[(arr[i] % k + k) % k]++;
        }
        if(mp[0] & 1) return false; 
        for(int i = 1 ; i < k ; i++){
            if(mp[i] != mp[k - i]) return false;
        }
        return true;
    }
};