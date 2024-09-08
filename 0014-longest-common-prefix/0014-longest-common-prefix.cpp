class Solution {
public:
    static bool compare(string s1, string s2){
        if(s1.length() < s2.length())
            return true;
        else return false;
    }
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end(), compare);
        int n = strs[0].length();
        int len = strs.size();
        int i = 0;
        string ans = "";
        while(i < n){
            int j = 0;
            bool isAns = true;
            while(j < len - 1){
                if(strs[j][i] != strs[j + 1][i]){
                    isAns = false;
                    break;
                }
                j++;
            }
            if(!isAns) break;
            ans += strs[j][i++];
        }
        return ans;
    }
};