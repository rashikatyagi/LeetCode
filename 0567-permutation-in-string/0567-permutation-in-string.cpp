class Solution {
public:
    bool check(vector<int> a, vector<int> b){
        for(int i = 0 ; i < 26 ; i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> fre1(26, 0);
        vector<int> fre2(26, 0);
        int n = s1.length();
        int m = s2.length();
        if(n > m) return false;
        for(char ch : s1){
            fre1[ch - 'a']++;
        }
        for(int i = 0 ; i < n ; i++){
            fre2[s2[i] - 'a']++;
        }
        if(check(fre1, fre2)) return true;
        for(int i = n ; i < m ; i++){
            fre2[s2[i] - 'a']++;
            fre2[s2[i - n] - 'a']--;
            if(check(fre1, fre2)) return true;
        }
        return false;
    }
};