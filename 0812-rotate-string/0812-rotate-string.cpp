class Solution {
public:
    bool rotateString(string s, string goal) {
        int len1 = s.length();
        int len2 = goal.length();
        if(len1 != len2) return false;
        s.append(s);
        return (s.find(goal) != string::npos);
    }
};