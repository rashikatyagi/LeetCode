class compare{
public:
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int &it : arr){
            mp[it]++;
        }
        if(k == 0) return mp.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for(auto &it : mp){
            pq.push(make_pair(it.first, it.second));
        }
        while(k >= pq.top().second){
            k -= pq.top().second;
            pq.pop();
        }
        return pq.size();
    }
};