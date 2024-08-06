class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26, 0);
        for(char &ch : word){
            arr[ch - 'a']++;
        }
        sort(arr.begin(), arr.end(), [](const int &a, const int &b){
        return a > b;
    });
        
        int count = 1;
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++){
            ans += count * arr[i];
            if((i + 1) % 8 == 0) count++;
        }
        return ans;
    }
    
};