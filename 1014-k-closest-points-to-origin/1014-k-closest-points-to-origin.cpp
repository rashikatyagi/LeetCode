class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>> pq;
        for(int i = 0 ; i < points.size() ; i++){
            double dist = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            pq.push(make_pair(-dist, make_pair(points[i][0], points[i][1])));
        }
        vector<vector<int>> ans;
        while((k--) != 0){
            auto it = pq.top();
            pq.pop();
            ans.push_back({it.second.first, it.second.second});
        }
        return ans;
    }
};