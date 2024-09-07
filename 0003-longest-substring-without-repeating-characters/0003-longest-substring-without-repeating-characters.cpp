class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> fre(255, 0);
        int maxLength = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(fre[s[j]] == 0){
                    maxLength = max(maxLength, j - i + 1);
                    fre[s[j]]++;
                }
                else{
                    fill(fre.begin(), fre.end(), 0);
                    break;
                }
            }
        }
        return maxLength;
    }
};