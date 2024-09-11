class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxLength = 0;
        unordered_map<char, int> mp;
        int left = 0, right = 0;
        int maxFreq = 0;
        while(right < n){
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);
            int len = right - left + 1;
            int changes = len - maxFreq;
            if(changes <= k){
                maxLength = max(maxLength, len);
            }
            else{
                // if(mp[s[left]] == maxFreq) maxFreq--;
                mp[s[left]]--;
                left++;
            }
            right++;
        }
        return maxLength;
    }
};