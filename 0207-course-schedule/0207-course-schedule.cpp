class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        int n = prerequisites.size();
        for(int i = 0 ; i < n ; i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> indegree(numCourses, 0);
        for(int i = 0 ; i < n ; i++){
            indegree[prerequisites[i][1]]++;
        }
        queue<int> q;
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            count++;
            int frontnode = q.front();
            q.pop();
            for(auto it : adj[frontnode]){
                indegree[it]--;

                if(indegree[it] == 0) q.push(it);
            }
        }
        return count == numCourses;
    }
};