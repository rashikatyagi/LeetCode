class Solution {
public:
    void generate(int n, int opening, int closing, string curr, vector<string> &ans){
        if(opening == n && closing == n){
            ans.push_back(curr);
            return;
        }
        if(opening < n && closing < n){
            generate(n, opening + 1, closing, curr + '(', ans);
            if(opening > closing) generate(n, opening, closing + 1, curr + ')', ans);
        }
        else if(opening == n){
            generate(n, opening, closing + 1, curr + ')', ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, 0, 0, "", ans);
        return ans;
    }
};