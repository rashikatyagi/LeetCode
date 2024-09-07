class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int maxLength = 0;
        int index = 0;
        int j = 0;
        while(j < n){
            if(mp.find(s[j]) == mp.end() || mp[s[j]] < index){
                maxLength = max(maxLength, j - index + 1);
                mp[s[j]] = j;
            }
            else{
                index = mp[s[j]] + 1;
                continue;
            }
            j++;
        }
        return maxLength;
    }
};