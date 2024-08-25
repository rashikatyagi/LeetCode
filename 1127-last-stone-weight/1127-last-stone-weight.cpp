class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int &it : stones){
            pq.push(it);
        }
        while(pq.size() > 1){
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            if(s1 != s2){
                pq.push(abs(s1 - s2));
            }
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};