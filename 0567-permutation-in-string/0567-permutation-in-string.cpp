class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        int n = s1.length();
        int m = s2.length();
        for(int i = 0 ; i <= m - n ; i++){
            string temp = s2.substr(i, n);
            sort(temp.begin(), temp.end());
            if(s1 == temp) return true;
        }
        return false;
    }
};