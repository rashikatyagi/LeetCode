class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i = 0 ; i < s.length() ; i++){
            if(!st.empty() && s[i] == ')' && st.top() == '(') st.pop();
            else st.push(s[i]);
        }
        return st.size();
    }
};