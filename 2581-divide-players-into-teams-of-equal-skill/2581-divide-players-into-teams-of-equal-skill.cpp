class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if(n == 2){
            return skill[0] * skill[1];
        }
        sort(skill.begin(), skill.end());
        long long int answer = 0;
        long long int prev_sum = -1;
        int start = 0;
        int end = n - 1;
        while(start < end){
            if(prev_sum != -1 && skill[start] + skill[end] != prev_sum){
                return -1;
            }
            prev_sum = skill[start] + skill[end];
            answer += (skill[start] * skill[end]);
            start++; end--;
        }
        return answer;
    }
};