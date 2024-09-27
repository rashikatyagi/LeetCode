class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int countN = 0;
        int countY = 0;
        for(int i = 0 ; i < n ; i++){
            if(customers[i] == 'Y') countY++;
        }
        int minPenalty = INT_MAX;
        int penalty;
        int answer = 0;
        for(int hour = 0 ; hour <= n ; hour++){
            if(hour != 0){
                if(customers[hour - 1] == 'Y'){
                    countY--;
                }
                else{
                    countN++;
                }
            }
            penalty = countN + countY;
            if(minPenalty > penalty){
                minPenalty = penalty;
                answer = hour;
            }
        }
        return answer;
    }
};