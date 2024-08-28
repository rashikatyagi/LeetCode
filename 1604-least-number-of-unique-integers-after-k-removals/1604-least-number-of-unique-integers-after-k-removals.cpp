class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int count = 1;
        for(int i = 1 ; i < arr.size() ; i++){
            if(arr[i] == arr[i - 1]) count++;
            else{
                pq.push(count);
                count = 1;
            }
        }
        pq.push(count);
        while(k >= pq.top()){
            k -= pq.top();
            pq.pop();
        }
        return pq.size();
    }
};