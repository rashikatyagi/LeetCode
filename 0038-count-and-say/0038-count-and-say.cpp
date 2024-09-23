class Solution {
public:
    string countAndSay(int N) {
        if(N == 1){
            return "1";
        }
        string s = countAndSay(N - 1);
        int len = s.length();
        string ans = "";
        int i = 0, j = 0;
        while(i < len && j < len){
            while(j < len && s[i] == s[j]) j++;
            ans += to_string(j - i);
            ans.push_back(s[i]);
            i = j;
        }
        return ans;
    }
};