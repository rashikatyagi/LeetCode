class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if(n == 2){
            return skill[0] * skill[1];
        }
        //total skill for each pair = (total skills) / (n / 2) ->number of teams
        int total = accumulate(skill.begin(), skill.end(), 0);
        int teamskill = 0;
        if(total % (n / 2) != 0) return -1;
        else{
            teamskill = total / (n / 2);
        }
        // element-frequency mapping
        unordered_map<int, int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[skill[i]]++;
        }

        long long answer = 0;
        for(int i = 0 ; i < n - 1 ; i++){
            if(mp[skill[i]] < 1) continue;
            int required = teamskill - skill[i];
            if(mp.find(required) == mp.end() || mp[required] < 1){
                return -1;
            }
            else{
                if(required == skill[i] && mp[required] <= 1) return -1;
                else{
                    answer += required * skill[i];
                    mp[required]--;
                    mp[skill[i]]--;
                }
            }
            
        }
        return answer;
    }
};