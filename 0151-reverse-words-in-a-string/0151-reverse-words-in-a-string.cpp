class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        int j = 0;
        while(s[j] == ' '){
            j++;
        }
        int i;
        int prev = n;
        for(i = n - 1 ; i >= j ; i--){
            if(s[i] == ' '){
                ans += s.substr(i + 1, prev - i - 1);
                if(prev - i - 1 != 0) ans += " ";
                prev = i;
            }
        }
        ans += s.substr(i + 1, prev - i - 1);
        return ans;
    }
};