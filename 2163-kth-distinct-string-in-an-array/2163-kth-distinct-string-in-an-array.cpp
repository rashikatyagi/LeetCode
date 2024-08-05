class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for(auto s : arr){
            mp[s]++;
        }
        string ans = "";
        for(auto s : arr){
            if(mp[s] == 1){
                k--;
                if(k == 0) ans += s;
            }
        }
        return ans;
    }
};