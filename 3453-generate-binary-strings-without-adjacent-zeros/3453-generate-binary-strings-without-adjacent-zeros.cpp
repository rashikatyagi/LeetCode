class Solution {
public:
    void generate(int n, string &currstring, vector<string> &ans){
        int len = currstring.length();
        if(len == n){
            ans.push_back(currstring);
            return;
        }
        if(len == 0 || currstring[len - 1] != '0'){
            currstring.push_back('0');
            generate(n, currstring, ans);
            currstring.pop_back();
            currstring.push_back('1');
            generate(n, currstring, ans);
            currstring.pop_back();
        }
        else{
            currstring.push_back('1');
            generate(n, currstring, ans);
            currstring.pop_back();

        }
    }
    vector<string> validStrings(int n) {
        vector<string> answer;
        string temp = "";
        generate(n, temp, answer);
        return answer;
    }
};