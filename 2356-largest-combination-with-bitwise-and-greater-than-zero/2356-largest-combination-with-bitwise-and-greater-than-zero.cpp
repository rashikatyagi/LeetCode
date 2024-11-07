class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int answer = 0;
        for(int i = 0 ; i <= 24 ; i++){
            int currBits = 0;
            for(int j = 0 ; j < n ; j++){
                if((candidates[j] >> i) & 1) currBits++;
            }
            answer = max(answer, currBits);
        }
        return answer;
    }
};