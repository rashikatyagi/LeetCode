class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto &it : piles){
            pq.push(it);
        }
        while(k--){
            int temp = pq.top();
            pq.pop();
            temp -= floor(temp / 2);
            pq.push(temp);
        }
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};