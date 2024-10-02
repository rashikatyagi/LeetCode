class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        // priority queue of element and index
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0 ; i < n ; i++){
            pq.push({arr[i], i});
        }
        int rank = 0;
        int prev_element = -1;
        vector<int> answer(n, 0);
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int element = front.first;
            int index = front.second;
            if(rank == 0 || prev_element != element){
                rank++;
            }
            answer[index] = rank;
            prev_element = element;
        }
        return answer;
    }
};