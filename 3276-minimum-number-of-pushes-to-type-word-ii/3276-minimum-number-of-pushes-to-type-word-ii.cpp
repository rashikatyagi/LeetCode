class Solution {
public:
    
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for(char s : word){
            mp[s]++;
        }
        vector<pair<char, int> > arr(mp.begin(), mp.end());
        auto comp = [](const pair<char, int> &a, const pair<char, int> &b){
        return a.second > b.second;
    };
        sort(arr.begin(), arr.end(), comp);
        
        int count = 1;
        int ans = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            ans += count * arr[i].second;
            if((i + 1) % 8 == 0) count++;
        }
        return ans;
    }
};