class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int maxLength = 0;
        int index = 0;
        for(int j = 0 ; j < n ; j++){
            if(mp.find(s[j]) == mp.end()){
                maxLength = max(maxLength, j - index + 1);
                mp[s[j]] = j;
            }
            else{
                j = mp[s[j]];
                index = j + 1;
                mp.clear();
            }
        }
        return maxLength;
    }
};