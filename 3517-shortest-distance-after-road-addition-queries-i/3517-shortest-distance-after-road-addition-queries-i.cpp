class Solution {
public:
    int shortestPath(vector<vector<int>> &adj, vector<int> &parent, int source, int destination){
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int currnode = q.front();
            q.pop();
            for(auto it : adj[currnode]){
                if(parent[it] == -1){
                    parent[it] = currnode;
                    q.push(it);
                }
            }
        }
        int pathlength = 0;
        int temp = destination;
        while(temp != source){
            pathlength++;
            temp = parent[temp];
        }
        return pathlength;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> answer;
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < n - 1 ; i++){
            adj[i].push_back(i + 1);
        }
        for(int i = 0 ; i < queries.size() ; i++){
            int u = queries[i][0];
            int v = queries[i][1];
            adj[u].push_back(v);
            //adj[v].push_back(u);
            vector<int> parent(n, -1);
            int currpathlength = shortestPath(adj, parent, 0, n - 1);
            answer.push_back(currpathlength);
        }
        return answer;
    }
};