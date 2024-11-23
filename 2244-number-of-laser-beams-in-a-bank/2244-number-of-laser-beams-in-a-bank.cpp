class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int answer = 0;
        int prev = 0;
        for(int i = 0 ; i < n ; i++){
            int count = 0;
            for(char ch : bank[i]){
                if(ch == '1') count++;
            }
            answer += (count * prev);
            if(count != 0){
                prev = count;
            }
        }
        return answer;
    }
};