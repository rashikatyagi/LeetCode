class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto s : details){
            if(s[11] == '6' && s[12] > '0') ans++;
            else if(s[11] > '6') ans++;
        }
        return ans;
    }
};