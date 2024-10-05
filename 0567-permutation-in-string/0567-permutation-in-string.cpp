class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n > m) return false;
        vector<int> frequency1(26, 0);
        vector<int> frequency2(26, 0);
        for(int i = 0 ; i < n ; i++){
            frequency1[s1[i] - 'a']++;
            frequency2[s2[i] - 'a']++;
        }
        if(frequency1 == frequency2) return true;
        for(int i = n ; i < m ; i++){
            frequency2[s2[i] - 'a']++;
            frequency2[s2[i - n] - 'a']--;
            if(frequency1 == frequency2) return true;
        }
        return false;
    }
};