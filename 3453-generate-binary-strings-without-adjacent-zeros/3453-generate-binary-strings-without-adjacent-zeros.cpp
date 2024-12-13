class Solution {
public:
    void generate(int n, string currstring, vector<string> &ans){
        int len = currstring.length();
        if(len == n){
            ans.push_back(currstring);
            return;
        }
        if(len == 0 || currstring[len - 1] != '0'){
            generate(n, currstring + '0', ans);
            generate(n, currstring + '1', ans);
        }
        else generate(n, currstring + '1', ans);
    }
    vector<string> validStrings(int n) {
        vector<string> answer;
        generate(n, "", answer);
        return answer;
    }
};