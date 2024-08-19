class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans = accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> pq;
        for(auto &it : piles){
            pq.push(it);
        }
        while(k--){
            int temp = pq.top();
            pq.pop();
            ans -= (temp / 2);
            pq.push(temp - (temp / 2));
        }
        return ans;
    }
};