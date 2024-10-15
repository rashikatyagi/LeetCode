class Solution {
public:
    long long minimumSteps(string s) {
        long long answer = 0;
        int point = 0;
        for(int index = 0 ; index < s.length() ; index++){
            if(s[index] == '0'){
                answer += (index - point++);
            }
        }
        return answer;
    }
};