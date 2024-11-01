class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        if(n == 1 || n == 2) return s;
        stack<char> st;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(st.size() < 2) st.push(s[i]);
            else if(st.top() != s[i]) st.push(s[i]);
            else{
                char first = st.top();
                st.pop();
                char second = st.top();
                st.push(first);
                if(second != s[i]) st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};