class Solution {
public:
    string countAndSay(int N) {
        if(N == 1){
            return "1";
        }
        string s = countAndSay(N - 1);
        int len = s.length();
        vector<int> fre(len, 1);
        for(int i = 1 ; i < len ; i++){
            if(s[i] == s[i - 1]){
                fre[i] += fre[i - 1];
            }
        }
        string ans = "";
        for(int i = 1 ; i < len ; i++){
            if(s[i] != s[i - 1]){
                ans += to_string(fre[i - 1]);
                ans.push_back(s[i - 1]);
            }
        }
        ans += to_string(fre[len - 1]);
        ans.push_back(s[len - 1]);
        return ans;
    }
};