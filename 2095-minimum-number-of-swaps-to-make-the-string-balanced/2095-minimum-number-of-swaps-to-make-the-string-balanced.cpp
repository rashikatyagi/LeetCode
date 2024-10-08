class Solution {
public:
    int minSwaps(string s) {
        stack<int> st;
        for(char ch : s){
            if(ch == '[') st.push(ch);
            else{
                if(st.empty()) continue;
                else if(st.top() == '[') st.pop();
            }
        }
        return (st.size() + 1) / 2;
    }
};