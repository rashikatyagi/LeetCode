class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        if(n == 1) return 1;
        stack<char> st;
        st.push(s[0]);
        for(int i = 1 ; i < n ; i++){
            if(s[i] == 'B' && !st.empty() && st.top() == 'A'){
                st.pop();
            }
            else if(s[i] == 'D' && !st.empty() && st.top() == 'C'){
                st.pop();
            }
            else st.push(s[i]);
        }
        return st.size();
    }
};