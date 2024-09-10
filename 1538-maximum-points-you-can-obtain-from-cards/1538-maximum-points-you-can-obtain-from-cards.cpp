class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for(int i = 0 ; i < k ; i++){
            sum += cardPoints[i];
        }
        if(k == n) return sum;
        int max_points = sum;
        for(int i = n - 1, j = k - 1 ; i >= n - k ; i--, j--){
            sum = sum - cardPoints[j] + cardPoints[i];
            max_points = max(max_points, sum);
        }
        return max_points;
    }
};