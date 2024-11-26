class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        vector<int> indegree(numCourses, 0);
        int n = prerequisites.size();
        for(int i = 0 ; i < n ; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int frontnode = q.front();
            q.pop();
            ans.push_back(frontnode);
            for(auto it : adj[frontnode]){
                indegree[it]--;

                if(indegree[it] == 0) q.push(it);
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};